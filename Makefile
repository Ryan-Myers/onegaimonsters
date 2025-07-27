BASENAME  = onegaimonsters
NON_MATCHING ?= 0
# Unknonwn yet
LIBULTRA_VERSION_DEFINE := -DBUILD_VERSION=7 -DBUILD_VERSION_STRING=\"2.0J\"

# Whether to hide commands or not
VERBOSE ?= 0
ifeq ($(VERBOSE),0)
  V := @
endif

PRINT = printf
GREP  = grep -rl

# Colors

# Whether to colorize build messages
COLOR ?= 1
GCC_COLOR := -fno-diagnostics-color

ifeq ($(COLOR),1)
NO_COL  := \033[0m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
PINK    := \033[0;35m
CYAN    := \033[0;36m
COLORIZE := -c
GCC_COLOR :=
endif

# Common build print status function
define print
  @$(PRINT) "$(GREEN)$(1) $(YELLOW)$(2)$(GREEN) -> $(BLUE)$(3)$(NO_COL)\n"
endef

# Directories
BIN_DIRS  = assets
BUILD_DIR = build
SRC_DIR   = src
# Workaround for an ultralib dir in src/ for now.
LIBULTRA_DIR = src/ultralib
ULTRALIB_DIR = ultralib
ASM_DIRS  = asm asm/data asm/nonmatchings asm/data/libultra 
ASM_DIRS += asm/overlays/code1 asm/data/overlays/code1
ASM_DIRS += asm/overlays/code2 asm/data/overlays/code2
ASM_DIRS += asm/overlays/code3 asm/data/overlays/code3
HASM_DIRS = $(SRC_DIR)/hasm $(LIBULTRA_DIR)/src/os $(LIBULTRA_DIR)/src/gu $(LIBULTRA_DIR)/src/libc
LIBULTRA_SRC_DIRS  = $(LIBULTRA_DIR) $(LIBULTRA_DIR)/src $(LIBULTRA_DIR)/src/audio
LIBULTRA_SRC_DIRS += $(LIBULTRA_DIR)/src/debug $(LIBULTRA_DIR)/src/gu $(LIBULTRA_DIR)/src/io
LIBULTRA_SRC_DIRS += $(LIBULTRA_DIR)/src/libc $(LIBULTRA_DIR)/src/os $(LIBULTRA_DIR)/src/sc
LIBULTRA_SRC_DIRS += $(LIBULTRA_DIR)/src/vimodes

SRC_DIRS = $(SRC_DIR) $(LIBULTRA_SRC_DIRS)
SYMBOLS_DIR = splat/symbols

TOOLS_DIR = tools

UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)

ifeq ($(OS),Windows_NT)
	$(error Native Windows is currently unsupported for building this repository, use WSL instead c:)
else ifeq ($(UNAME_S),Linux)
	ifneq ($(filter aarch%,$(UNAME_M)),)
		DETECTED_OS := linux-arm
	else
		DETECTED_OS := linux
	endif
else ifeq ($(UNAME_S),Darwin)
	DETECTED_OS := macos
endif

KMC_DIR         := $(TOOLS_DIR)/gcc_kmc/$(DETECTED_OS)/2.7.2
KMC_GCC         := $(KMC_DIR)/gcc
KMC_BINUTILS    := $(KMC_DIR)/as

# Files

S_FILES         = $(foreach dir,$(ASM_DIRS) $(HASM_DIRS),$(wildcard $(dir)/*.s))
C_FILES         = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
BIN_FILES       = $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))

O_FILES := $(foreach file,$(S_FILES),$(BUILD_DIR)/$(basename $(file)).o) \
           $(foreach file,$(C_FILES),$(BUILD_DIR)/$(basename $(file)).o) \
           $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(basename $(file)).o)


find-command = $(shell which $(1) 2>/dev/null)

# Tools

ifeq ($(shell type mips-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
	CROSS := mips-linux-gnu-
else ifeq ($(shell type mips64-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
	CROSS := mips64-linux-gnu-
else ifeq ($(shell type mips64-elf-ld >/dev/null 2>/dev/null; echo $$?), 0)
	CROSS := mips64-elf-
endif

AS       = $(CROSS)as
LD       = $(CROSS)ld
OBJCOPY  = $(CROSS)objcopy
VENV     = .venv
PYTHON   = $(VENV)/bin/python3
GCC      = gcc

#Options
CC       = COMPILER_PATH=$(KMC_DIR) $(KMC_GCC)
SPLAT    ?= $(PYTHON) -m splat split
CRC      = $(TOOLS_DIR)/n64crc $(BUILD_DIR)/$(BASENAME).z64 $(COLORIZE)

OPT_FLAGS      = -O2

MIPSISET       = -mips2

# Not sure about which F3D version is being used yet.
DEFINES := _FINALROM NDEBUG TARGET_N64 F3DEX_GBI_2

VERIFY = verify

ifeq ($(NON_MATCHING),1)
	MATCHDEFS += NON_MATCHING=1
	MATCHDEFS += AVOID_UB=1
	VERIFY = no_verify
	MIPSISET = -mips2
	C_STANDARD := -std=gnu99
else
	C_STANDARD := -std=gnu90
endif

DEFINES += $(MATCHDEFS)
C_DEFINES := $(foreach d,$(DEFINES),-D$(d)) $(LIBULTRA_VERSION_DEFINE) -D_MIPS_SZLONG=32 -D__USE_ISOC99 -D_LANGUAGE_C
ASM_DEFINES = $(foreach d,$(DEFINES),$(if $(findstring =,$(d)),--defsym $(d),))

INCLUDE_CFLAGS  = -I . -I include -I include/libc  -I include/PR -I include/sys -I $(BIN_DIRS) -I $(SRC_DIR) -I $(LIBULTRA_DIR)
INCLUDE_CFLAGS += -I $(ULTRALIB_DIR)/include -I $(ULTRALIB_DIR)/include/libc -I $(ULTRALIB_DIR)/include/PR -I $(ULTRALIB_DIR)/include/sys
INCLUDE_CFLAGS += -I $(ULTRALIB_DIR)/src/audio -I $(ULTRALIB_DIR)/include/PRinternal
INCLUDE_CFLAGS += -I $(LIBULTRA_DIR)/src/gu -I $(LIBULTRA_DIR)/src/libc -I $(LIBULTRA_DIR)/src/io  -I $(LIBULTRA_DIR)/src/sc 
INCLUDE_CFLAGS += -I $(LIBULTRA_DIR)/src/audio -I $(LIBULTRA_DIR)/src/os

ASFLAGS        = -march=vr4300 -mabi=32 -G0 $(ASM_DEFINES) -no-pad-sections -EB $(INCLUDE_CFLAGS)
OBJCOPYFLAGS   = -O binary

# Pad to 16MB if matching, otherwise build to a necessary minimum of 1.004MB
ifeq ($(NON_MATCHING),1)
  OBJCOPYFLAGS += --pad-to=0x101000 --gap-fill=0xFF
else
  OBJCOPYFLAGS += --pad-to=0x1000000 --gap-fill=0xFF
endif

#IDO Warnings to Ignore. These are coding style warnings we don't follow
CC_WARNINGS := -w

CFLAGS := -G 0 -nostdinc -fno-PIC -G 0 -mno-abicalls
CFLAGS += $(C_DEFINES)
CFLAGS += $(INCLUDE_CFLAGS)


CHECK_WARNINGS := -Wall -Wextra -Wno-format-security -Wno-unknown-pragmas -Wunused-function -Wno-unused-parameter
CHECK_WARNINGS += -Werror-implicit-function-declaration -Wno-unused-variable -Wno-missing-braces -Wno-int-conversion -Wno-main
CHECK_WARNINGS += -Wno-builtin-declaration-mismatch -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -Wno-switch
CC_CHECK := $(GCC) -fsyntax-only -fno-builtin -funsigned-char $(C_STANDARD) -D_LANGUAGE_C $(CHECK_WARNINGS) $(INCLUDE_CFLAGS) $(C_DEFINES) $(GCC_COLOR)

# Only add -m32 for x86_64 machines.
ifneq ($(filter x86_64%,$(UNAME_M)),)
	CC_CHECK += -m32
endif

TARGET     = $(BUILD_DIR)/$(BASENAME)
LD_SCRIPT  = splat/$(BASENAME).ld

LD_FLAGS   = -T $(LD_SCRIPT) -T $(SYMBOLS_DIR)/undefined_syms.txt  -T $(SYMBOLS_DIR)/undefined_funcs_auto.txt  -T $(SYMBOLS_DIR)/undefined_syms_auto.txt
LD_FLAGS  += -Map $(TARGET).map

### Optimisation Overrides
####################### LIBULTRA #########################

$(BUILD_DIR)/$(OLD_LIBULTRA_DIR)/%.c.o: OPT_FLAGS := -O2
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/%.c.o: OPT_FLAGS := -O3
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/mips1/%.c.o: OPT_FLAGS := -O2
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/os/%.c.o: OPT_FLAGS := -O1
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/%.c.o: OPT_FLAGS := -O1
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/vimgr.c.o: OPT_FLAGS := -O2
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/pimgr.c.o: OPT_FLAGS := -O2
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/motor.c.o: OPT_FLAGS := -O2
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/xprintf.c.o : OPT_FLAGS := -O3
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/env.c.o: OPT_FLAGS := -g
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/llcvt.c.o: OPT_FLAGS := -O1
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/llcvt.c.o: MIPSISET := -mips3 -32
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/ll.c.o: OPT_FLAGS := -O1
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/ll.c.o: MIPSISET := -mips3 -32
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/ldiv.c.o: OPT_FLAGS := -O3
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/ldiv.c.o: MIPSISET := -mips2
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/xldtob.c.o: OPT_FLAGS := -O3
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/xldtob.c.o: MIPSISET := -mips2

# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/mips1/%.c.o: MIPSISET := -mips1
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/pimgr.c.o: MIPSISET := -mips1
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/sc/sched.c.o: MIPSISET := -mips1
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/io/motor.c.o: MIPSISET := -mips1
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/env.c.o: MIPSISET := -mips1

# $(BUILD_DIR)/src/libultra/cents2ratio.c.o: OPT_FLAGS := -g
# $(BUILD_DIR)/src/libultra/cents2ratio.c.o: MIPSISET := -mips2


# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/cents2ratio.c.o: OPT_FLAGS := -g
# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/audio/cents2ratio.c.o: MIPSISET := -mips2

#Ignore warnings for libultra files
$(BUILD_DIR)/$(LIBULTRA_DIR)/%.c.o: CC_WARNINGS := -w
$(BUILD_DIR)/$(LIBULTRA_DIR)/%.c.o: CC_CHECK := :

### Targets

default: all

all: $(VERIFY)

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(HASM_DIRS) $(BIN_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

verify: $(TARGET).z64
	$(V)$(CRC)
ifeq ($(NON_MATCHING),0)
	@(sha1sum -c --quiet splat/$(BASENAME).sha1 \
	&& $(PRINT) "$(GREEN)Verify:$(NO_COL)\
	 $(YELLOW)OK$(NO_COL)\n")
	$(V)$(PRINT) "$(YELLOW)    __\n .\`_  _\`.\n| | \`| | |\n| |_|._| |\n \`. __ .\'$(NO_COL)\n\n"
else
	$(V)$(PRINT) "$(GREEN)Build Complete!$(NO_COL)\n"
endif

no_verify: $(TARGET).z64
	$(V)$(CRC)
	$(V)$(PRINT) "$(GREEN)Build Complete!$(NO_COL)\n"

extract:
	$(SPLAT) splat/$(BASENAME).yaml

setup:
#Set up a python venv so we don't get warnings about breaking system packages.
	$(V)python3 -m venv $(VENV)
#Installing the splat dependencies
	$(V)$(PYTHON) -m pip install -r requirements.txt
	$(V)make -C $(TOOLS_DIR)

clean:
	rm -rf $(BUILD_DIR)

clean_src:
	rm -rf $(BUILD_DIR)/asm
	rm -rf $(BUILD_DIR)/libultra
	rm -rf $(BUILD_DIR)/src
	
cleanall:
	rm -rf $(BUILD_DIR)

distclean: clean
	rm -rf $(ASM_DIRS)
	rm -rf $(BIN_DIRS)
	rm -rf assets
	rm -f $(SYMBOLS_DIR)/*auto.txt
	rm -f $(LD_SCRIPT)

distcleanall: cleanall
	rm -rf assets
	rm -f $(SYMBOLS_DIR)/*auto.txt
	rm -f splat/onegaimonsters.ld

#When you just need to wipe old symbol names and re-extract
cleanextract: distclean extract

#Put the build folder into expected for use with asm-differ. Only run this with a matching build.
expected: verify
	mkdir -p expected
	rm -rf expected/$(BUILD_DIR)
	cp -r $(BUILD_DIR)/ expected/

### Recipes

$(TARGET).elf: dirs $(LD_SCRIPT) $(O_FILES)
	@$(PRINT) "$(GREEN)Linking: $(BLUE)$@$(NO_COL)\n"
	$(V)$(LD) $(LD_FLAGS) -o $@

$(BUILD_DIR)/%.o: %.c
	$(call print,Compiling:,$<,$@)
	$(V)$(CC_CHECK) -MMD -MP -MT $@ -MF $(BUILD_DIR)/$*.d $<
	$(V)$(CC) -c $(CFLAGS) $(CC_WARNINGS) $(OPT_FLAGS) $(MIPSISET) -o $@ $<

# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/llcvt.c.o: $(LIBULTRA_DIR)/src/libc/llcvt.c
# 	$(call print,Compiling mips3:,$<,$@)
# 	@$(CC) -c $(CFLAGS) $(CC_WARNINGS) $(OPT_FLAGS) $(MIPSISET) -o $@ $<
# 	$(V)$(PYTHON) $(TOOLS_DIR)/patchmips3.py $@ || rm $@

# $(BUILD_DIR)/$(LIBULTRA_DIR)/src/libc/ll.c.o: $(LIBULTRA_DIR)/src/libc/ll.c
# 	$(call print,Compiling mips3:,$<,$@)
# 	@$(CC) -c $(CFLAGS) $(CC_WARNINGS) $(OPT_FLAGS) $(MIPSISET) -o $@ $<
# 	$(V)$(PYTHON) $(TOOLS_DIR)/patchmips3.py $@ || rm $@

$(BUILD_DIR)/%.o: %.s
	$(call print,Assembling:,$<,$@)
	$(V)$(AS) $(ASFLAGS) -MD $(BUILD_DIR)/$*.d -o $@ $< 

$(BUILD_DIR)/%.o: %.bin
	$(call print,Linking Binary:,$<,$@)
	$(V)$(LD) -r -b binary -o $@ $<

$(TARGET).z64: $(TARGET).elf
	$(call print,Objcopy:,$<,$@)
	$(V)$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

### Settings
.PHONY: all clean cleanextract default
SHELL = /bin/bash -e -o pipefail

-include $(BUILD_DIR)/**/*.d

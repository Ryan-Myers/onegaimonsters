MAKE = make

CC := gcc
CFLAGS := -I . -Wall -Wextra -Wno-unused-parameter -pedantic -std=c99 $(OPT) -s
LDFLAGS := -lm

UNAME_S := $(shell uname -s)
ifeq ($(OS),Windows_NT)
	DETECTED_OS := windows
	HOST_TRIPLE := x86_64-pc-windows-msvc
else ifeq ($(UNAME_S),Linux)
	DETECTED_OS := linux
	HOST_TRIPLE := x86_64-unknown-linux-musl
else ifeq ($(UNAME_S),Darwin)
	DETECTED_OS := mac
	MAKE := gmake
	CPPFLAGS += -xc++
	HOST_TRIPLE := x86_64-apple-darwin
endif


ifeq ($(DETECTED_OS),windows)
$(error This repo does not support compiling on native Windows yet, please use WSL instead.)
endif


KMC_DIR         := gcc_kmc/$(DETECTED_OS)/2.7.2
KMC_GCC         := $(KMC_DIR)/gcc
KMC_BINUTILS    := $(KMC_DIR)/as

default: all

all: n64crc $(KMC_GCC) $(KMC_BINUTILS)

clean:
	$(RM) -rf $(KMC_DIR) gcc_kmc
	$(RM) -f n64crc

distclean: clean

n64crc: n64crc.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

.PHONY: all clean distclean

$(KMC_GCC): | $(KMC_DIR)
	wget https://github.com/decompals/mips-gcc-2.7.2/releases/latest/download/gcc-2.7.2-$(DETECTED_OS).tar.gz
	tar xf gcc-2.7.2-$(DETECTED_OS).tar.gz -C $(KMC_DIR)
	$(RM) gcc-2.7.2-$(DETECTED_OS).tar.gz

$(KMC_BINUTILS): | $(KMC_DIR)
	wget https://github.com/decompals/mips-binutils-2.6/releases/latest/download/binutils-2.6-$(DETECTED_OS).tar.gz
	tar xf binutils-2.6-$(DETECTED_OS).tar.gz -C $(KMC_DIR)
	$(RM) binutils-2.6-$(DETECTED_OS).tar.gz

$(KMC_DIR):
	mkdir -p $@

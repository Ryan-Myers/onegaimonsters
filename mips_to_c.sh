#!/bin/bash


if [[ -z "$1" ]]; then
    echo "Usage: $0 <asm_function_name>"
    exit 1
fi

if [[ ! -d m2cfiles ]]; then
    echo "Creating m2cfiles directory..."
    mkdir -p m2cfiles
fi

if [[ ! -f ctx.c ]]; then
    echo "ctx.c not found, creating a new one..."
    ./generate_ctx.sh
fi

if [[ ! -f .venv/bin/python3 ]]; then
    echo "Python virtual environment not found, please set it up first."
    exit 1
fi

if [[ ! -d tools/m2c ]]; then
    echo "m2c tool not found, please ensure it is installed in the tools directory."
    exit 1
fi

if [[ ! -d asm ]]; then
    echo "asm directory not found, please ensure it exists."
    exit 1
fi

if [[ $1 == "--file" || $1 == "-f" ]]; then
    if [[ -z "$2" || -z "$3" ]]; then
        echo "Usage: $0 --file <asm_file> <asm_function_name>"
        exit 1
    fi
    ASMFILE="$2"
    FUNCTION="$3"
else
    ASMFILE=$(find asm -type f -name "*$1.s" | head -n 1)
    FUNCTION="$1"
    if [[ -z "$ASMFILE" ]]; then
        echo "No assembly file found for function $1."
        exit 1
    fi
fi

echo "Using assembly file: $ASMFILE for function: $FUNCTION"

printf '#include "../ctx.c"\n' > m2cfiles/"$FUNCTION".c
.venv/bin/python3 tools/m2c/m2c.py --target mips-gcc-c --pointer-style right --context ctx.c -f "$FUNCTION" "$ASMFILE" >> m2cfiles/"$FUNCTION".c

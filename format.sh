#!/usr/bin/env bash

FORMAT_OPTS="-i -style=file"
TIDY_OPTS="-p . --fix --fix-errors"
COMPILER_OPTS="-fno-builtin -std=gnu90 -Iinclude -Isrc -D_LANGUAGE_C -DNON_MATCHING"

shopt -s globstar

if (( $# > 0 )); then
    echo "Formatting file(s) $*"
    echo "Running clang-format..."
    clang-format ${FORMAT_OPTS} "$@"
    echo "Running clang-tidy..."
    clang-tidy ${TIDY_OPTS} "$@" -- ${COMPILER_OPTS} &> /dev/null
    echo "Adding missing final new lines..."
    sed -i -e '$a\' "$@"
    echo "Done formatting file(s) $*"
    exit
fi

echo "Formatting C files. This will take a bit"

# Create a list of files to process, excluding the ultralib directory
# The -print0 and xargs -0 combo is the safest way to handle filenames
# that might contain spaces or other special characters.
files_to_process() {
    find src -path "src/ultralib" -prune -o -type f -name "*.c" -print0
}

echo "Running clang-format..."
files_to_process | xargs -0 clang-format ${FORMAT_OPTS}

echo "Running clang-tidy..."
files_to_process | xargs -0 clang-tidy ${TIDY_OPTS} -- ${COMPILER_OPTS} &> /dev/null

echo "Adding missing final new lines..."
files_to_process | xargs -0 sed -i -e '$a\'

echo "Done formatting all files."
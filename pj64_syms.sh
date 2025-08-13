#!/bin/bash

# This script reformats a symbol file into a CSV format:
# address_without_0x,code,symbol_name

# Check if a filename is provided as an argument
if [ $# -eq 0 ]; then
    echo "Usage: $0 <input_file>"
    echo "Example: $0 symbols.txt"
    exit 1
fi

input_file="$1"
# Create a nicely named output file, e.g., "symbols_formatted.csv"
output_file="${input_file%.*}_formatted.csv"

# Check if the input file exists
if [ ! -f "$input_file" ]; then
    echo "Error: File '$input_file' not found!"
    exit 1
fi

# Use awk to process the file:
# -F ' = '   : Sets the field separator to " = " (space-equals-space).
#              This cleanly separates the symbol name into $1 and the rest into $2.
# '{ ... }'  : The action to perform on each line.
#
# Inside the action:
# 1. split($2, addr_part, ";"): Splits the second field (e.g., "0x8015BE20; // ...")
#    by the semicolon, storing the parts in an array named `addr_part`.
#    The address we want is now in `addr_part[1]`.
# 2. sub("0x", "", addr_part[1]): Removes the "0x" prefix from the address.
# 3. printf "%s,code,%s\n", ...: Prints the final formatted string.
#    - %s: The address (now without "0x")
#    - code: The hardcoded literal string "code"
#    - %s: The symbol name from the first field ($1)

awk -F ' = ' '
{
    split($2, addr_part, ";")
    sub("0x", "", addr_part[1])
    printf "%s,code,%s\n", addr_part[1], $1
}' "$input_file" > "$output_file"

echo "Symbols reformatted and saved to: $output_file"
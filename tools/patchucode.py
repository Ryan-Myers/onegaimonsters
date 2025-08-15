#!/usr/bin/env python3
import sys
import struct

def modify_elf_flags(filename):
    with open(filename, 'r+b') as f:
        # Read ELF header
        f.seek(0)
        elf_header = f.read(52)
        
        # Verify it's an ELF file
        if elf_header[:4] != b'\x7fELF':
            print("Not an ELF file")
            return
        
        # Read current e_flags (at offset 36)
        f.seek(36)
        current_flags = struct.unpack('>I', f.read(4))[0]
        
        # Clear the o32 ABI bit (0x1000)
        new_flags = current_flags & ~0x1000
        
        # Write back the modified flags
        f.seek(36)
        f.write(struct.pack('>I', new_flags))

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <elf_file>")
        sys.exit(1)
    modify_elf_flags(sys.argv[1])
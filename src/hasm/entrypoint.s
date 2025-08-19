.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .bss

.equ mainThreadStackSize, 0x2000

dlabel mainThreadStack
.space mainThreadStackSize
.size mainThreadStack, mainThreadStackSize

.section .text, "ax"

glabel entrypoint
.ent entrypoint
    lui        $t0, %hi(main_BSS_START)
    addiu      $t0, $t0, %lo(main_BSS_START)
    lui        $t1, %hi(main_BSS_SIZE)
    addiu      $t1, $t1, %lo(main_BSS_SIZE)
  .clear_bytes:
    sw         $zero, 0x0($t0)
    sw         $zero, 0x4($t0)
    addi       $t0, $t0, 0x8
    addi       $t1, $t1, -0x8
    bnez       $t1, .clear_bytes
     nop
    lui        $t2, %hi(boot)
    addiu      $t2, $t2, %lo(boot)
    lui        $sp, %hi(mainThreadStack + mainThreadStackSize)
    jr         $t2
     addiu     $sp, $sp, %lo(mainThreadStack + mainThreadStackSize)
    nop
    nop
    nop
    nop
    nop
.end entrypoint

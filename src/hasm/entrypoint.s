.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .bss

glabel mainThreadStack
.space 0x2000
glabel mainThreadStackEnd

.section .text, "ax"

leaf entrypoint
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
    lui        $sp, %hi(mainThreadStackEnd)
    jr         $t2
     addiu     $sp, $sp, %lo(mainThreadStackEnd)
    nop
    nop
    nop
    nop
    nop
.end entrypoint

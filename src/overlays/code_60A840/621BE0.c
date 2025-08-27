#include "common.h"
#include "DB50.h"

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_800177A0_621BE0);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_80017874_621CB4);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_800199E4_623E24);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001AA28_624E68);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001B5EC_625A2C);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001B81C_625C5C);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001C13C_62657C);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001C6C4_626B04);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001C73C_626B7C);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001C9F8_626E38);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001CB50_626F90);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001CD1C_62715C);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001D520_627960);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001D738_627B78);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001D9A0_627DE0);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001DA20_627E60);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001E2D0_628710);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001E860_628CA0);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001F110_629550);

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001F144_629584);

#ifdef NON_EQUIVALENT
// This feels "right" , but isn't even close to matching.
extern s32 D_code_60A840_80053698_65DAD8[12]; // VRAM Addresses
extern s32 D_code_60A840_800536C8_65DB08[12]; // ROM Addresses
extern s32 D_code_60A840_800536F8_65DB38[12]; // The end of ROM Addresses.

void func_code_60A840_8001F1F0_629630(s32 arg0) {
    s32 sp10[3][12];
    s32 i;

    for (i = 0; i < 12; i++) {
        sp10[0][i] = D_code_60A840_80053698_65DAD8[i];
    }
    for (i = 0; i < 12; i++) {
        sp10[1][i] = D_code_60A840_800536C8_65DB08[i];
    }
    for (i = 0; i < 12; i++) {
        sp10[2][i] = D_code_60A840_800536F8_65DB38[i];
    }
    osInvalICache(sp10[0][arg0], sp10[2][arg0] - sp10[1][arg0]);
    loadOverlayAtAddress(sp10[1][arg0], sp10[0][arg0], sp10[2][arg0] - sp10[1][arg0]);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001F1F0_629630);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/code_60A840/621BE0", func_code_60A840_8001F2FC_62973C);

INCLUDE_RODATA("asm/nonmatchings/overlays/code_60A840/621BE0", D_code_60A840_80053698_65DAD8);

INCLUDE_RODATA("asm/nonmatchings/overlays/code_60A840/621BE0", D_code_60A840_800536C8_65DB08);

INCLUDE_RODATA("asm/nonmatchings/overlays/code_60A840/621BE0", D_code_60A840_800536F8_65DB38);

INCLUDE_RODATA("asm/nonmatchings/overlays/code_60A840/621BE0", D_code_60A840_80053728_65DB68);

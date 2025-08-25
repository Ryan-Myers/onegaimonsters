#include "DB50.h"
#include "1E210.h"
#include "1F3B0.h"
#include "common.h"

extern void func_800FF7A0(s32);
extern void func_800FF9D8(void);
extern void func_800FFABC(void *, f32, f32);
extern void func_80106140(void);
void func_80105A80(void *);
s32 func_80105F00(s32);

extern void *D_80157120;
extern s32 D_801529B8; // Almost definitely something like a struct or an array.
extern s32 D_80171E98;
extern s32 D_80174374;
extern s32 D_80184310; // Almost definitely something like a struct or an array.

void func_800FFF50(void) {
    func_80105A80(&D_80157120);
    while (func_80105F00(0) != 1) {}
}

/**
 * Loads Overlay 2 into memory
 */
void loadOverlay2(void) {
    LOAD_CODE_SEGMENT(o2);
}

/**
 * Loads Overlay 3 into memory
 */
void loadOverlay3(void) {
    LOAD_CODE_SEGMENT(o3);
}

/**
 * Loads Overlay 4 into memory
 */
void loadOverlay4(void) {
    LOAD_CODE_SEGMENT(o4);
}

/**
 * Loads an overlay of a given size into memory.
 * It can only load 0x18000 at a time, so this will do it in chunks if needed.
 * @param devAddr The offset in ROM where the new code lives
 * @param dramAddr The RAM address to load the code into
 * @param size The size of overlay.
 */
void loadOverlayAtAddress(u32 devAddr, void *dramAddr, u32 size) {
    while (size != 0) {
        if (size < MAX_DMA_SIZE) {
            dmaOverlay(devAddr, dramAddr, size);
            size = 0;
        } else {
            dmaOverlay(devAddr, dramAddr, MAX_DMA_SIZE);
            size -= MAX_DMA_SIZE;
            devAddr += MAX_DMA_SIZE;
            dramAddr += MAX_DMA_SIZE;
        }
    }
}

extern s32 D_801883B0;
extern s32 D_80188E74;

void func_801001C4(s32 newVal) {
    s32 oldVal;

    oldVal = D_801883B0;
    D_801883B0 = newVal;
    D_80188E74 = oldVal;
}

/**
 * Loads overlays at code_1B4070, code_682020, and code_60A840
 */
void func_801001E4(void) {
    LOAD_DATA_SEGMENT_ALT(o67, o66); // Bug? Invalidates the previous overlay VRAM address
    ZERO_OVERLAY_BSS(o67);
    LOAD_DATA_SEGMENT_ALT(code_682020, o66); // Bug? Invalidates the same old VRAM address
    LOAD_DATA_SEGMENT(code_60A840);
}

void func_801003EC(s32 arg0) {
    void *temp_s0;

    if (arg0 < 2) {
        temp_s0 = (D_801529B8 << 5) + &D_80184310;
        func_800FF7A0(1);
        func_800FFABC(temp_s0, 0.0f, 2000.0f);
        func_800FF9D8();
    }
    if ((D_80188E74 == D_801883B0) || (func_80105F00(0) == 1)) {
        func_80110610(NULL);
        D_80174374 = D_80171E98;
    }
    func_80106140();
}

#ifdef NON_EQUIVALENT
void D_801A9FB0(s32 arg0);
void D_801AA5F4(s32 arg0);
void D_801B53CC(s32 arg0);
void D_801E290C(s32 arg0);
void D_801E30A4(s32 arg0);
void D_801E6290(s32 arg0);
void D_801F81D8(s32 arg0);
void D_801F8B14(s32 arg0);
void D_801F8CA8(s32 arg0);
void D_801F9804(s32 arg0);
void func_80013C90();        
void func_80013D60(s32 arg0);       
void func_80014BF0();        
void func_800171CC(u16 *);     
void func_8001CD1C();        
void func_8001D520(void);       
void func_8001D738(void); //void func_code_60A840_8001D738_627B78(void);
void func_8001F144(u16 *arg0); //void func_code_60A840_8001F144_629584(u16 *arg0)
void func_8001F1F0(s32 arg0); // void func_code_60A840_8001F1F0_629630(s32 arg0)
void func_801057F0();        
void func_80105CB0(s32);     
void func_80110560();        
void func_80110700();        
void func_80110730();        
void func_80110740();        
void func_801A9160();        
void func_801A91E0();        
void func_801A956C();        
void func_801A9664();        
void func_801DC8D0(s32 arg0);  // void func_o67_801DC8D0_1B4070(s32 arg0)
void func_801E07B0();        
void func_801E18E8();        
void func_801E2B40();        
void func_801E2D40();        
void func_801F74E0();        
void func_801F7680();        
void func_801F7A30();        
void func_801F7B5C();        
void func_801F81C0();        
void func_801F8370();        
void func_801F8410();        
void func_801F85B4();        
void func_801F91EC();        
extern s32 D_80152B84;
extern s32 D_80152B8C;
extern u8 D_80152BFE;
extern s32 D_80152C0C;
extern u16 D_80152C14;
extern u16 D_80157150;
extern u16 D_80157158;
extern u16 D_80157160;
extern u16 D_8015716C;
extern s32 D_80171E98;
extern s32 D_80172008;
extern s32 D_80174374;
extern void *D_80175870;
extern s32 D_80175D98;
extern s32 D_80184308;
extern u16 D_80184504;
extern u16 D_80184524;
extern u16 *D_80184F34;
extern s32 D_80187928;
extern s32 D_80187950;
extern s32 *D_801880C8;
extern s32 D_801883B0;
extern u32 D_801887D8;
extern s32 D_80188E74;
extern s32 D_8018903C;
extern s32 D_801AA0A0;
extern s32 D_801AA0B0;
extern s32 D_801AA840;
extern s32 D_801AAAB0;
extern s32 D_801CF9F0;
extern s32 D_801E0560;
extern s32 D_801E3A60;
extern s32 D_801E3C80;
extern s32 D_801E7370;
extern s32 D_801E76F0;
extern s32 D_801F2B60;
extern s32 D_801F6830;
extern s32 D_801F7420;
extern s32 D_801F7750;
extern s32 D_801F7DC0;
extern s32 D_801F7E50;
extern s32 D_801F84B0;
extern s32 D_801F85C0;
extern s32 D_801F8D00;
extern s32 D_801F8D20;
extern s32 D_801F8FE0;
extern s32 D_801F9850;
extern s32 D_801F9860;
extern s32 D_801F9AD0;
extern s32 D_801F9AE0;
extern s32 D_801F9CD0;
extern s32 D_801F9CF0;
extern s32 D_801FA170;
extern s32 D_801FA210;
extern s32 D_801FA360;
extern s32 D_801FA420;
extern s32 D_801FA470;
extern s32 D_801FAD10;
extern s32 D_801FAD20;
extern s32 D_801FC200;
extern s32 D_801FCB00;
extern s32 D_801FD880;
extern s32 D_801FE080;
extern s32 D_801FE1E0;
extern s32 D_801FE5F0;
extern s32 D_80201CB0;
extern s32 D_80202A50;
extern s32 D_80202A90;
extern s32 D_80203510;
extern s32 D_80203CF0;
extern s32 D_80204990;
extern s32 D_80204C30;
extern s32 D_80204F70;
extern s32 D_80205070;
extern s32 D_80205540;
extern s32 D_802056E0;
extern s32 D_802057D0;
extern s32 D_80205A00;
extern s32 D_80205AA0;
extern s32 D_80205DA0;
extern s32 D_80205EA0;
extern s32 D_80205EC0;
extern s32 D_80205F30;
extern s32 D_80205FA0;
extern s32 D_80205FB0;
extern s32 D_80205FC0;
extern s32 D_802060D0;
extern s32 D_802061A0;
extern s32 D_802061D0;
extern s32 D_80206200;
extern s32 D_80206360;
extern s32 D_80206450;
extern s32 D_80206480;
extern s32 D_80206690;
extern s32 D_802067C0;
extern s32 D_802067D0;
extern s32 D_80206800;
extern s32 D_80206820;
extern s32 D_802068A0;
extern s32 D_802068C0;
extern s32 D_80206980;
extern s32 D_80206A90;
extern s32 D_80206B60;
extern s32 D_80206BB0;
extern s32 D_80206C50;
extern s32 D_80206D10;
extern s32 D_80206DC0;
extern s32 D_80206F40;
extern s32 D_80206F80;
extern s32 D_80206F90;
extern s32 D_80207120;
extern s32 D_802071E0;
extern s32 D_80207200;
extern s32 D_80207290;
extern s32 D_802072A0;
extern s32 D_80207370;
extern s32 D_802073F0;
extern s32 D_80207450;
extern s32 D_80207500;
extern s32 D_802079C0;
extern s32 D_80207A00;
extern s32 D_80208220;
extern s32 D_802084D0;
extern s32 D_802085F0;
extern s32 D_80208680;
extern s32 D_80208DB0;
extern s32 func_801FCD80(void); //s32 func_o51_801FCD80_16D410(void)
extern s32 func_801FEDF0(void); //s32 func_o55_801FEDF0_188C80(void)
extern void func_802036B0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7); //void func_o19_802036B0_10E220(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7)
void mainproc(void *arg0) {
    s32 (*var_s0_16)();
    s32 (*var_s0_17)();
    s32 (*var_s0_18)();
    s32 (*var_s0_19)();
    s32 (*var_s0_20)();
    s32 *var_a0_2;
    s32 *var_a0_3;
    s32 *var_a1;
    s32 *var_a1_2;
    s32 *var_s0_101;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s0_7;
    s32 temp_s0_8;
    s32 temp_s6;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_a0_4;
    s32 var_s0;
    s32 var_s0_100;
    s32 var_s0_10;
    s32 var_s0_11;
    s32 var_s0_12;
    s32 var_s0_13;
    s32 var_s0_14;
    s32 var_s0_15;
    s32 var_s0_21;
    s32 var_s0_22;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s0_64;
    s32 var_s0_65;
    s32 var_s0_66;
    s32 var_s0_68;
    s32 var_s0_69;
    s32 var_s0_70;
    s32 var_s0_71;
    s32 var_s0_72;
    s32 var_s0_73;
    s32 var_s0_74;
    s32 var_s0_75;
    s32 var_s0_76;
    s32 var_s0_78;
    s32 var_s0_7;
    s32 var_s0_80;
    s32 var_s0_81;
    s32 var_s0_82;
    s32 var_s0_83;
    s32 var_s0_84;
    s32 var_s0_85;
    s32 var_s0_88;
    s32 var_s0_89;
    s32 var_s0_8;
    s32 var_s0_90;
    s32 var_s0_93;
    s32 var_s0_94;
    s32 var_s0_96;
    s32 var_s0_97;
    s32 var_s0_99;
    s32 var_s0_9;
    s32 var_s1_13;
    s32 var_s1_14;
    s32 var_s1_15;
    s32 var_s1_16;
    s32 var_s1_17;
    s32 var_s1_20;
    s32 var_s1_21;
    s32 var_s1_22;
    s32 var_s1_23;
    s32 var_s1_24;
    s32 var_s1_25;
    s32 var_s1_26;
    s32 var_s1_27;
    s32 var_s1_28;
    s32 var_s1_29;
    s32 var_s1_30;
    s32 var_s1_31;
    s32 var_s1_32;
    s32 var_s1_33;
    s32 var_s1_34;
    s32 var_s1_35;
    s32 var_s1_36;
    s32 var_s1_37;
    s32 var_s1_38;
    s32 var_s1_39;
    s32 var_s1_3;
    s32 var_s1_40;
    s32 var_s1_41;
    s32 var_s1_42;
    s32 var_s1_43;
    s32 var_s1_44;
    s32 var_s1_45;
    s32 var_s1_46;
    s32 var_s1_47;
    s32 var_s1_48;
    s32 var_s1_49;
    s32 var_s1_4;
    s32 var_s1_50;
    s32 var_s1_51;
    s32 var_s1_52;
    s32 var_s1_53;
    s32 var_s1_54;
    s32 var_s1_55;
    s32 var_s1_56;
    s32 var_s1_57;
    s32 var_s1_58;
    s32 var_s1_59;
    s32 var_s1_60;
    s32 var_s1_64;
    s32 var_s1_72;
    s32 var_s1_74;
    s32 var_s1_79;
    s32 var_s1_80;
    s32 var_s1_82;
    s32 var_s1_83;
    s32 var_s1_86;
    s32 var_s1_89;
    s32 var_s1_91;
    s32 var_s1_92;
    s32 var_v0_10;
    s32 var_v0_11;
    s32 var_v0_12;
    s32 var_v0_13;
    s32 var_v0_14;
    s32 var_v0_15;
    s32 var_v0_16;
    s32 var_v0_17;
    s32 var_v0_18;
    s32 var_v0_19;
    s32 var_v0_20;
    s32 var_v0_21;
    s32 var_v0_22;
    s32 var_v0_23;
    s32 var_v0_24;
    s32 var_v0_25;
    s32 var_v0_26;
    s32 var_v0_27;
    s32 var_v0_28;
    s32 var_v0_29;
    s32 var_v0_2;
    s32 var_v0_30;
    s32 var_v0_31;
    s32 var_v0_32;
    s32 var_v0_33;
    s32 var_v0_34;
    s32 var_v0_35;
    s32 var_v0_36;
    s32 var_v0_37;
    s32 var_v0_38;
    s32 var_v0_39;
    s32 var_v0_3;
    s32 var_v0_40;
    s32 var_v0_41;
    s32 var_v0_42;
    s32 var_v0_43;
    s32 var_v0_44;
    s32 var_v0_45;
    s32 var_v0_46;
    s32 var_v0_47;
    s32 var_v0_48;
    s32 var_v0_49;
    s32 var_v0_4;
    s32 var_v0_50;
    s32 var_v0_51;
    s32 var_v0_52;
    s32 var_v0_53;
    s32 var_v0_54;
    s32 var_v0_55;
    s32 var_v0_56;
    s32 var_v0_57;
    s32 var_v0_58;
    s32 var_v0_59;
    s32 var_v0_5;
    s32 var_v0_60;
    s32 var_v0_61;
    s32 var_v0_62;
    s32 var_v0_63;
    s32 var_v0_64;
    s32 var_v0_65;
    s32 var_v0_66;
    s32 var_v0_67;
    s32 var_v0_68;
    s32 var_v0_6;
    s32 var_v0_70;
    s32 var_v0_72;
    s32 var_v0_73;
    s32 var_v0_74;
    s32 var_v0_75;
    s32 var_v0_76;
    s32 var_v0_77;
    s32 var_v0_78;
    s32 var_v0_7;
    s32 var_v0_80;
    s32 var_v0_81;
    s32 var_v0_83;
    s32 var_v0_84;
    s32 var_v0_85;
    s32 var_v0_87;
    s32 var_v0_88;
    s32 var_v0_89;
    s32 var_v0_8;
    s32 var_v0_90;
    s32 var_v0_91;
    s32 var_v0_92;
    s32 var_v0_93;
    s32 var_v0_94;
    s32 var_v0_95;
    s32 var_v0_97;
    s32 var_v0_99;
    s32 var_v0_9;
    u8 *var_s1;
    u8 *var_s1_10;
    u8 *var_s1_11;
    u8 *var_s1_12;
    u8 *var_s1_18;
    u8 *var_s1_19;
    u8 *var_s1_2;
    u8 *var_s1_5;
    u8 *var_s1_61;
    u8 *var_s1_62;
    u8 *var_s1_63;
    u8 *var_s1_65;
    u8 *var_s1_66;
    u8 *var_s1_67;
    u8 *var_s1_6;
    u8 *var_s1_70;
    u8 *var_s1_71;
    u8 *var_s1_73;
    u8 *var_s1_75;
    u8 *var_s1_77;
    u8 *var_s1_7;
    u8 *var_s1_81;
    u8 *var_s1_84;
    u8 *var_s1_85;
    u8 *var_s1_87;
    u8 *var_s1_88;
    u8 *var_s1_8;
    u8 *var_s1_90;
    u8 *var_s1_9;
    u8 *var_s2_13;
    u8 *var_s2_14;
    u8 *var_s2_15;
    u8 *var_s2_16;
    u8 *var_s2_17;
    u8 *var_s2_20;
    u8 *var_s2_21;
    u8 *var_s2_22;
    u8 *var_s2_23;
    u8 *var_s2_24;
    u8 *var_s2_25;
    u8 *var_s2_26;
    u8 *var_s2_27;
    u8 *var_s2_28;
    u8 *var_s2_29;
    u8 *var_s2_30;
    u8 *var_s2_31;
    u8 *var_s2_32;
    u8 *var_s2_33;
    u8 *var_s2_34;
    u8 *var_s2_35;
    u8 *var_s2_36;
    u8 *var_s2_37;
    u8 *var_s2_38;
    u8 *var_s2_39;
    u8 *var_s2_3;
    u8 *var_s2_40;
    u8 *var_s2_41;
    u8 *var_s2_42;
    u8 *var_s2_43;
    u8 *var_s2_44;
    u8 *var_s2_45;
    u8 *var_s2_46;
    u8 *var_s2_47;
    u8 *var_s2_48;
    u8 *var_s2_49;
    u8 *var_s2_4;
    u8 *var_s2_50;
    u8 *var_s2_51;
    u8 *var_s2_52;
    u8 *var_s2_53;
    u8 *var_s2_54;
    u8 *var_s2_55;
    u8 *var_s2_56;
    u8 *var_s2_57;
    u8 *var_s2_58;
    u8 *var_s2_59;
    u8 *var_s2_60;
    u8 *var_s2_64;
    u8 *var_s2_68;
    u8 *var_s2_69;
    u8 *var_s2_72;
    u8 *var_s2_74;
    u8 *var_s2_76;
    u8 *var_s2_78;
    u8 *var_s2_79;
    u8 *var_s2_81;
    u8 *var_s2_82;
    u8 *var_s2_85;
    u8 *var_s2_88;
    u8 *var_s2_90;
    u8 *var_s2_91;
    void (*var_a0)(s32);
    void (*var_s0_102)(s32);
    void (*var_s0_23)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_24)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_25)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_26)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_27)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_28)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_29)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_30)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_31)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_32)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_33)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_34)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_35)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_36)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_37)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_38)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_39)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_40)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_41)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_42)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_43)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_44)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_45)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_46)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_47)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_48)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_49)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_5)();
    void (*var_s0_50)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_51)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_52)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_53)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_54)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_55)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_56)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_57)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_58)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_59)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_6)();
    void (*var_s0_60)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_61)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_62)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_63)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s0_67)(s32);
    void (*var_s0_77)(s32);
    void (*var_s0_79)(s32);
    void (*var_s0_86)();
    void (*var_s0_87)(s32);
    void (*var_s0_91)();
    void (*var_s0_92)(s32);
    void (*var_s0_95)(s32);
    void (*var_s0_98)(s32);
    void (*var_s1_68)();
    void (*var_s1_69)();
    void (*var_s1_76)(s32);
    void (*var_s2)();
    void (*var_s2_10)();
    void (*var_s2_11)();
    void (*var_s2_12)();
    void (*var_s2_18)();
    void (*var_s2_19)(s32);
    void (*var_s2_2)();
    void (*var_s2_5)();
    void (*var_s2_6)();
    void (*var_s2_61)(s32);
    void (*var_s2_62)(f32, f32, f32, f32, f32, f32, f32, f32);
    void (*var_s2_63)();
    void (*var_s2_65)();
    void (*var_s2_66)();
    void (*var_s2_67)();
    void (*var_s2_7)();
    void (*var_s2_70)();
    void (*var_s2_71)();
    void (*var_s2_73)(s32);
    void (*var_s2_75)();
    void (*var_s2_77)();
    void (*var_s2_8)();
    void (*var_s2_80)();
    void (*var_s2_83)();
    void (*var_s2_84)();
    void (*var_s2_86)(s32);
    void (*var_s2_87)();
    void (*var_s2_89)(s32);
    void (*var_s2_9)(s32);
    void **var_a1_3;
    void **var_s1_78;
    void **var_v0;
    void **var_v0_69;
    void **var_v0_71;
    void **var_v0_79;
    void **var_v0_82;
    void **var_v0_86;
    void **var_v0_96;
    void **var_v1;
    void **var_v1_2;
    void **var_v1_3;
    void *temp_v0_2;
    void *var_v0_98;

    func_80110560();
    func_80110740();
    func_800FFF50();
    temp_s6 = o4_ROM_START - o3_ROM_START;
    D_80174374 = 0;
    D_80188E74 = -1;
    D_801883B0 = -1;
    while (1) {
        switch (D_80174374) {                           /* switch 3; irregular */
        case 0x66:
            D_80174374 = -1;
            var_s0 = 0xF;
            var_v0 = &D_80175870 + 0x3C;
            do {
                *var_v0 = NULL;
                var_s0 -= 1;
                var_v0 -= 4;
            } while (var_s0 >= 0);
            func_801001E4();
            func_801DC8D0(0xCB);
            LOAD_CODE_SEGMENT(o2);
            LOAD_CODE_SEGMENT(o4);
            LOAD_OVERLAY(code_944550);
            // temp_s0 = o3_ROM_START - o2_ROM_START;
            // osInvalICache(func_801A9160, temp_s0);
            // loadOverlayAtAddress((u32) o2_ROM_START, func_801A9160, (u32) temp_s0);
            // bzero(&D_801CF9F0, (u32) &func_801DC8D0 - (u32) &D_801CF9F0);
            // var_s2 = func_801F74E0;
            // var_s1 = code_944550_ROM_START;
            // var_s0_2 = code_945D70_ROM_START - code_944550_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_2);
            // var_v0_2 = (u32) var_s0_2 > 0x17FFFU;
            // if (var_s0_2 != 0) {
            //     do {
            //         if (var_v0_2 == 0) {
            //             dmaOverlay((u32) var_s1, var_s2, (u32) var_s0_2);
            //             var_s0_2 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1, var_s2, 0x18000U);
            //             var_s0_2 += 0xFFFE8000;
            //             var_s1 += 0x18000;
            //             var_s2 += 0x18000;
            //         }
            //         var_v0_2 = (u32) var_s0_2 > 0x17FFFU;
            //     } while (var_s0_2 != 0);
            // }
            // bzero(&D_801F8D00, &D_801F8D20 - &D_801F8D00);
            func_801F81C0();
            var_a0 = D_801F8B14;
    block_658:
            func_80110610(var_a0);
            func_80110730();
            break;
        default:  
            var_s0_3 = 0xF;
            if (D_80174374 != 0x1C3) {

            } else {
                var_v1 = &D_80175870 + 0x3C;
                D_80174374 = -1;
                D_80187950 = 0;
                D_8018903C = (s32) D_80184524;
                do {
                    *var_v1 = NULL;
                    var_s0_3 -= 1;
                    var_v1 -= 4;
                } while (var_s0_3 >= 0);
                func_801001E4();
                func_80014BF0();
                func_800171CC(&D_80157158);
                func_8001CD1C();
                LOAD_CODE_SEGMENT(o3);
                LOAD_OVERLAY(o65);
                // osInvalICache(func_801DC8D0, temp_s6);
                // loadOverlayAtAddress((u32) o3_ROM_START, func_801DC8D0, (u32) temp_s6);
                // bzero(&D_801F7420, (u32) &func_801F74E0 - (u32) &D_801F7420);
                // var_s2_2 = func_801F74E0;
                // var_s1_2 = o65_ROM_START;
                // var_s0_4 = o66_ROM_START - o65_ROM_START;
                // osInvalICache(func_801F74E0, var_s0_4);
                // var_v0_3 = (u32) var_s0_4 > 0x17FFFU;
                // if (var_s0_4 != 0) {
                //     do {
                //         if (var_v0_3 == 0) {
                //             dmaOverlay((u32) var_s1_2, var_s2_2, (u32) var_s0_4);
                //             var_s0_4 = 0;
                //         } else {
                //             dmaOverlay((u32) var_s1_2, var_s2_2, 0x18000U);
                //             var_s0_4 += 0xFFFE8000;
                //             var_s1_2 += 0x18000;
                //             var_s2_2 += 0x18000;
                //         }
                //         var_v0_3 = (u32) var_s0_4 > 0x17FFFU;
                //     } while (var_s0_4 != 0);
                // }
                // bzero(&D_801F9CD0, &D_801F9CF0 - &D_801F9CD0);
                func_801F74E0();
                func_801A9664();
                var_a0 = D_801B53CC;
                func_80110610(var_a0);
                func_80110730();
            }
            break;
        case 0x0: 
            D_80174374 = -1;
            LOAD_OVERLAY(o1);
            // var_s0_5 = func_801A9160;
            // var_s2_3 = o1_ROM_START;
            // var_s1_3 = o2_ROM_START - o1_ROM_START;
            // osInvalICache(func_801A9160, var_s1_3);
            // var_v0_4 = (u32) var_s1_3 > 0x17FFFU;
            // if (var_s1_3 != 0) {
            //     do {
            //         if (var_v0_4 == 0) {
            //             dmaOverlay((u32) var_s2_3, var_s0_5, (u32) var_s1_3);
            //             var_s1_3 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_3, var_s0_5, 0x18000U);
            //             var_s1_3 += 0xFFFE8000;
            //             var_s2_3 += 0x18000;
            //             var_s0_5 += 0x18000;
            //         }
            //         var_v0_4 = (u32) var_s1_3 > 0x17FFFU;
            //     } while (var_s1_3 != 0);
            // }
            // bzero(&D_801AA840, &D_801AAAB0 - &D_801AA840);
            func_801A91E0();
            var_a0 = D_801AA5F4;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x1: 
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(2);
            LOAD_OVERLAY(code_926CF0);
            // var_s0_6 = func_801A9160;
            // var_s2_4 = code_926CF0_ROM_START;
            // var_s1_4 = code_927C30_ROM_START - code_926CF0_ROM_START;
            // osInvalICache(func_801A9160, var_s1_4);
            // var_v0_5 = (u32) var_s1_4 > 0x17FFFU;
            // if (var_s1_4 != 0) {
            //     do {
            //         if (var_v0_5 == 0) {
            //             dmaOverlay((u32) var_s2_4, var_s0_6, (u32) var_s1_4);
            //             var_s1_4 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_4, var_s0_6, 0x18000U);
            //             var_s1_4 += 0xFFFE8000;
            //             var_s2_4 += 0x18000;
            //             var_s0_6 += 0x18000;
            //         }
            //         var_v0_5 = (u32) var_s1_4 > 0x17FFFU;
            //     } while (var_s1_4 != 0);
            // }
            // bzero(&D_801AA0A0, &D_801AA0B0 - &D_801AA0A0);
            func_801A9160();
            var_a0 = D_801A9FB0;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0xA: 
            D_80174374 = -1;
            var_s0_7 = 0xF;
            func_801001E4();
            var_v1_2 = &D_80175870 + 0x3C;
            D_8018903C = 0xC8;
            do {
                *var_v1_2 = NULL;
                var_s0_7 -= 1;
                var_v1_2 -= 4;
            } while (var_s0_7 >= 0);
            *(&D_80175870 + 0x18) = (void *)0x1FA;
            *(&D_80175870 + 0x1C) = (void *)0x1FB;
            func_801DC8D0(1);
            LOAD_CODE_SEGMENT(o2);
            LOAD_OVERLAY(o3);
            // temp_s0_2 = o3_ROM_START - o2_ROM_START;
            // osInvalICache(func_801A9160, temp_s0_2);
            // loadOverlayAtAddress((u32) o2_ROM_START, func_801A9160, (u32) temp_s0_2);
            // bzero(&D_801CF9F0, (u32) &func_801DC8D0 - (u32) &D_801CF9F0);
            // var_s2_5 = func_801F74E0;
            // var_s1_5 = o66_ROM_START;
            // var_s0_8 = o67_ROM_START - o66_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_8);
            // var_v0_6 = (u32) var_s0_8 > 0x17FFFU;
            // if (var_s0_8 != 0) {
            //     do {
            //         if (var_v0_6 == 0) {
            //             dmaOverlay((u32) var_s1_5, var_s2_5, (u32) var_s0_8);
            //             var_s0_8 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_5, var_s2_5, 0x18000U);
            //             var_s0_8 += 0xFFFE8000;
            //             var_s1_5 += 0x18000;
            //             var_s2_5 += 0x18000;
            //         }
            //         var_v0_6 = (u32) var_s0_8 > 0x17FFFU;
            //     } while (var_s0_8 != 0);
            // }
            // bzero(&D_801FA470, &D_80201CB0 - &D_801FA470);
            func_801F7B5C();
            var_a0 = D_801F9804;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x1E:
            D_80174374 = -1;
            func_801001E4();
            func_801057F0();
            func_801DC8D0(1);
            LOAD_CODE_SEGMENT(o2);
            LOAD_CODE_SEGMENT(o3);
            LOAD_CODE_SEGMENT(o4);
            // temp_s0_3 = o3_ROM_START - o2_ROM_START;
            // osInvalICache(func_801A9160, temp_s0_3);
            // loadOverlayAtAddress((u32) o2_ROM_START, func_801A9160, (u32) temp_s0_3);
            // bzero(&D_801CF9F0, (u32) &func_801DC8D0 - (u32) &D_801CF9F0);
            // temp_s0_4 = o5_ROM_START - o4_ROM_START;
            // osInvalICache(func_801F74E0, temp_s0_4);
            // loadOverlayAtAddress((u32) o4_ROM_START, func_801F74E0, (u32) temp_s0_4);
            // bzero(&D_80206360, &D_80207370 - &D_80206360);
            func_801A956C();
            var_a0 = D_801B53CC;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x1F:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(5);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o5);
            // var_s2_6 = func_801F74E0;
            // var_s1_6 = o5_ROM_START;
            // var_s0_9 = o6_ROM_START - o5_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_9);
            // var_v0_7 = (u32) var_s0_9 > 0x17FFFU;
            // if (var_s0_9 != 0) {
            //     do {
            //         if (var_v0_7 == 0) {
            //             dmaOverlay((u32) var_s1_6, var_s2_6, (u32) var_s0_9);
            //             var_s0_9 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_6, var_s2_6, 0x18000U);
            //             var_s0_9 += 0xFFFE8000;
            //             var_s1_6 += 0x18000;
            //             var_s2_6 += 0x18000;
            //         }
            //         var_v0_7 = (u32) var_s0_9 > 0x17FFFU;
            //     } while (var_s0_9 != 0);
            // }
            // bzero(&D_80206D10, &D_802084D0 - &D_80206D10);
            func_801A9664();
            var_a0 = D_801B53CC;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x20:
            D_80174374 = -1;
            LOAD_CODE_SEGMENT(o3);
            LOAD_CODE_SEGMENT(o4);
            // temp_s0_5 = o5_ROM_START - o4_ROM_START;
            // osInvalICache(func_801F74E0, temp_s0_5);
            // loadOverlayAtAddress((u32) o4_ROM_START, func_801F74E0, (u32) temp_s0_5);
            // bzero(&D_80206360, &D_80207370 - &D_80206360);
            var_a0 = D_801B53CC;
            D_80172008 = 0x2710;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x21:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(1);
            LOAD_CODE_SEGMENT(o3);
            LOAD_CODE_SEGMENT(o4);
            // temp_s0_6 = o5_ROM_START - o4_ROM_START;
            // osInvalICache(func_801F74E0, temp_s0_6);
            // loadOverlayAtAddress((u32) o4_ROM_START, func_801F74E0, (u32) temp_s0_6);
            // bzero(&D_80206360, &D_80207370 - &D_80206360);
            var_a0 = D_801B53CC;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x22:
            D_80174374 = -1;
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o6);
            // var_s2_7 = func_801F74E0;
            // var_s1_7 = o6_ROM_START;
            // var_s0_10 = o7_ROM_START - o6_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_10);
            // var_v0_8 = (u32) var_s0_10 > 0x17FFFU;
            // if (var_s0_10 != 0) {
            //     do {
            //         if (var_v0_8 == 0) {
            //             dmaOverlay((u32) var_s1_7, var_s2_7, (u32) var_s0_10);
            //             var_s0_10 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_7, var_s2_7, 0x18000U);
            //             var_s0_10 += 0xFFFE8000;
            //             var_s1_7 += 0x18000;
            //             var_s2_7 += 0x18000;
            //         }
            //         var_v0_8 = (u32) var_s0_10 > 0x17FFFU;
            //     } while (var_s0_10 != 0);
            // }
            // bzero(&D_801FE080, &D_802057D0 - &D_801FE080);
            func_801A9664();
            var_a0 = D_801B53CC;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x23:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(4);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o6);
            // var_s2_8 = func_801F74E0;
            // var_s1_8 = o6_ROM_START;
            // var_s0_11 = o7_ROM_START - o6_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_11);
            // var_v0_9 = (u32) var_s0_11 > 0x17FFFU;
            // if (var_s0_11 != 0) {
            //     do {
            //         if (var_v0_9 == 0) {
            //             dmaOverlay((u32) var_s1_8, var_s2_8, (u32) var_s0_11);
            //             var_s0_11 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_8, var_s2_8, 0x18000U);
            //             var_s0_11 += 0xFFFE8000;
            //             var_s1_8 += 0x18000;
            //             var_s2_8 += 0x18000;
            //         }
            //         var_v0_9 = (u32) var_s0_11 > 0x17FFFU;
            //     } while (var_s0_11 != 0);
            // }
            // bzero(&D_801FE080, &D_802057D0 - &D_801FE080);
            func_801A9664();
            var_a0 = D_801B53CC;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x24:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(6);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o7);
            // var_s2_9 = func_801DC8D0;
            // var_s1_9 = o7_ROM_START;
            // var_s0_12 = o8_ROM_START - o7_ROM_START;
            // osInvalICache(func_801DC8D0, var_s0_12);
            // var_v0_10 = (u32) var_s0_12 > 0x17FFFU;
            // if (var_s0_12 != 0) {
            //     do {
            //         if (var_v0_10 == 0) {
            //             dmaOverlay((u32) var_s1_9, var_s2_9, (u32) var_s0_12);
            //             var_s0_12 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_9, var_s2_9, 0x18000U);
            //             var_s0_12 += 0xFFFE8000;
            //             var_s1_9 += 0x18000;
            //             var_s2_9 += 0x18000;
            //         }
            //         var_v0_10 = (u32) var_s0_12 > 0x17FFFU;
            //     } while (var_s0_12 != 0);
            // }
            // bzero(&D_801FA360, (u32) &func_802036B0 - (u32) &D_801FA360);
            func_801A9664();
            var_a0 = D_801B53CC;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x26:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(8);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o6);
            // var_s2_10 = func_801F74E0;
            // var_s1_10 = o6_ROM_START;
            // var_s0_13 = o7_ROM_START - o6_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_13);
            // var_v0_11 = (u32) var_s0_13 > 0x17FFFU;
            // if (var_s0_13 != 0) {
            //     do {
            //         if (var_v0_11 == 0) {
            //             dmaOverlay((u32) var_s1_10, var_s2_10, (u32) var_s0_13);
            //             var_s0_13 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_10, var_s2_10, 0x18000U);
            //             var_s0_13 += 0xFFFE8000;
            //             var_s1_10 += 0x18000;
            //             var_s2_10 += 0x18000;
            //         }
            //         var_v0_11 = (u32) var_s0_13 > 0x17FFFU;
            //     } while (var_s0_13 != 0);
            // }
            // bzero(&D_801FE080, &D_802057D0 - &D_801FE080);
            func_801A9664();
            var_a0 = D_801B53CC;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x27:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(9);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o6);
            // var_s2_11 = func_801F74E0;
            // var_s1_11 = o6_ROM_START;
            // var_s0_14 = o7_ROM_START - o6_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_14);
            // var_v0_12 = (u32) var_s0_14 > 0x17FFFU;
            // if (var_s0_14 != 0) {
            //     do {
            //         if (var_v0_12 == 0) {
            //             dmaOverlay((u32) var_s1_11, var_s2_11, (u32) var_s0_14);
            //             var_s0_14 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_11, var_s2_11, 0x18000U);
            //             var_s0_14 += 0xFFFE8000;
            //             var_s1_11 += 0x18000;
            //             var_s2_11 += 0x18000;
            //         }
            //         var_v0_12 = (u32) var_s0_14 > 0x17FFFU;
            //     } while (var_s0_14 != 0);
            // }
            // bzero(&D_801FE080, &D_802057D0 - &D_801FE080);
            func_801A9664();
            var_a0 = D_801B53CC;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x64:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(0xC8);
            LOAD_CODE_SEGMENT(o3);
            LOAD_CODE_SEGMENT(o4);
            // temp_s0_7 = o5_ROM_START - o4_ROM_START;
            // osInvalICache(func_801F74E0, temp_s0_7);
            // loadOverlayAtAddress((u32) o4_ROM_START, func_801F74E0, (u32) temp_s0_7);
            // bzero(&D_80206360, &D_80207370 - &D_80206360);
            func_801A9664();
            var_a0 = D_801B53CC;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x65:
            D_80174374 = -1;
            func_801001E4();
            if ((D_80152B84 < 5) && (D_80152B84 >= 0)) {
                func_801DC8D0(0xC9);
            }
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o50);
            // var_s2_12 = func_801F74E0;
            // var_s1_12 = o50_ROM_START;
            // var_s0_15 = o51_ROM_START - o50_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_15);
            // var_v0_13 = (u32) var_s0_15 > 0x17FFFU;
            // if (var_s0_15 != 0) {
            //     do {
            //         if (var_v0_13 == 0) {
            //             dmaOverlay((u32) var_s1_12, var_s2_12, (u32) var_s0_15);
            //             var_s0_15 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_12, var_s2_12, 0x18000U);
            //             var_s0_15 += 0xFFFE8000;
            //             var_s1_12 += 0x18000;
            //             var_s2_12 += 0x18000;
            //         }
            //         var_v0_13 = (u32) var_s0_15 > 0x17FFFU;
            //     } while (var_s0_15 != 0);
            // }
            // bzero(&D_801FCB00, (u32) &func_801FCD80 - (u32) &D_801FCB00);
            switch (D_80152B84) {                       /* switch 4; irregular */
                default:                                    /* switch 4 */
                    LOAD_OVERLAY(o51);
                    // var_s0_16 = func_801FCD80;
                    // var_s2_13 = o51_ROM_START;
                    // var_s1_13 = o52_ROM_START - o51_ROM_START;
                    // osInvalICache(func_801FCD80, var_s1_13);
                    // var_v0_14 = (u32) var_s1_13 > 0x17FFFU;
                    // if (var_s1_13 != 0) {
                    //     do {
                    //         if (var_v0_14 == 0) {
                    //             dmaOverlay((u32) var_s2_13, var_s0_16, (u32) var_s1_13);
                    //             var_s1_13 = 0;
                    //         } else {
                    //             dmaOverlay((u32) var_s2_13, var_s0_16, 0x18000U);
                    //             var_s1_13 += 0xFFFE8000;
                    //             var_s2_13 += 0x18000;
                    //             var_s0_16 += 0x18000;
                    //         }
                    //         var_v0_14 = (u32) var_s1_13 > 0x17FFFU;
                    //     } while (var_s1_13 != 0);
                    // }
                    // var_a0_2 = &D_80203CF0;
                    // var_a1 = &D_80203CF0;
                    // bzero(var_a0_2, var_a1 - var_a0_2);
                    break;
                case 4:                                     /* switch 4 */
                    LOAD_OVERLAY(o55);
                    // var_s0_17 = func_801FEDF0;
                    // var_s2_14 = o55_ROM_START;
                    // var_s1_14 = o56_ROM_START - o55_ROM_START;
                    // osInvalICache(func_801FEDF0, var_s1_14);
                    // var_v0_15 = (u32) var_s1_14 > 0x17FFFU;
                    // if (var_s1_14 != 0) {
                    //     do {
                    //         if (var_v0_15 == 0) {
                    //             dmaOverlay((u32) var_s2_14, var_s0_17, (u32) var_s1_14);
                    //             var_s1_14 = 0;
                    //         } else {
                    //             dmaOverlay((u32) var_s2_14, var_s0_17, 0x18000U);
                    //             var_s1_14 += 0xFFFE8000;
                    //             var_s2_14 += 0x18000;
                    //             var_s0_17 += 0x18000;
                    //         }
                    //         var_v0_15 = (u32) var_s1_14 > 0x17FFFU;
                    //     } while (var_s1_14 != 0);
                    // }
                    // var_a0_2 = &D_80203510;
                    // var_a1 = &D_80203510;
                    // bzero(var_a0_2, var_a1 - var_a0_2);
                    break;
                case 3:                                     /* switch 4 */
                    LOAD_OVERLAY(o52);
                    // var_s0_18 = func_801FCD80;
                    // var_s2_15 = o52_ROM_START;
                    // var_s1_15 = o53_ROM_START - o52_ROM_START;
                    // osInvalICache(func_801FCD80, var_s1_15);
                    // var_v0_16 = (u32) var_s1_15 > 0x17FFFU;
                    // if (var_s1_15 != 0) {
                    //     do {
                    //         if (var_v0_16 == 0) {
                    //             dmaOverlay((u32) var_s2_15, var_s0_18, (u32) var_s1_15);
                    //             var_s1_15 = 0;
                    //         } else {
                    //             dmaOverlay((u32) var_s2_15, var_s0_18, 0x18000U);
                    //             var_s1_15 += 0xFFFE8000;
                    //             var_s2_15 += 0x18000;
                    //             var_s0_18 += 0x18000;
                    //         }
                    //         var_v0_16 = (u32) var_s1_15 > 0x17FFFU;
                    //     } while (var_s1_15 != 0);
                    // }
                    // bzero(&D_801FE5F0, (u32) &func_801FEDF0 - (u32) &D_801FE5F0);
                    if (D_80152B8C < 0xFB) {
                        LOAD_OVERLAY(o53);
                        // var_s0_19 = func_801FEDF0;
                        // var_s2_16 = o53_ROM_START;
                        // var_s1_16 = o54_ROM_START - o53_ROM_START;
                        // osInvalICache(func_801FEDF0, var_s1_16);
                        // var_v0_17 = (u32) var_s1_16 > 0x17FFFU;
                        // if (var_s1_16 != 0) {
                        //     do {
                        //         if (var_v0_17 == 0) {
                        //             dmaOverlay((u32) var_s2_16, var_s0_19, (u32) var_s1_16);
                        //             var_s1_16 = 0;
                        //         } else {
                        //             dmaOverlay((u32) var_s2_16, var_s0_19, 0x18000U);
                        //             var_s1_16 += 0xFFFE8000;
                        //             var_s2_16 += 0x18000;
                        //             var_s0_19 += 0x18000;
                        //         }
                        //         var_v0_17 = (u32) var_s1_16 > 0x17FFFU;
                        //     } while (var_s1_16 != 0);
                        // }
                        // var_a0_2 = &D_80208680;
                        // var_a1 = &D_80208680;
                        // bzero(var_a0_2, var_a1 - var_a0_2);
                    } else {
                        LOAD_OVERLAY(o54);
                        // var_s0_20 = func_801FEDF0;
                        // var_s2_17 = o54_ROM_START;
                        // var_s1_17 = o55_ROM_START - o54_ROM_START;
                        // osInvalICache(func_801FEDF0, var_s1_17);
                        // var_v0_18 = (u32) var_s1_17 > 0x17FFFU;
                        // if (var_s1_17 != 0) {
                        //     do {
                        //         if (var_v0_18 == 0) {
                        //             dmaOverlay((u32) var_s2_17, var_s0_20, (u32) var_s1_17);
                        //             var_s1_17 = 0;
                        //         } else {
                        //             dmaOverlay((u32) var_s2_17, var_s0_20, 0x18000U);
                        //             var_s1_17 += 0xFFFE8000;
                        //             var_s2_17 += 0x18000;
                        //             var_s0_20 += 0x18000;
                        //         }
                        //         var_v0_18 = (u32) var_s1_17 > 0x17FFFU;
                        //     } while (var_s1_17 != 0);
                        // }
                        // var_a0_2 = &D_802085F0;
                        // var_a1 = &D_802085F0;
                        // bzero(var_a0_2, var_a1 - var_a0_2);
                    }
                    break;
                }
            func_801A9664();
            var_a0 = D_801B53CC;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x2: 
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(0xCA);
            LOAD_CODE_SEGMENT(o2);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(code_943580);
            // temp_s0_8 = o3_ROM_START - o2_ROM_START;
            // osInvalICache(func_801A9160, temp_s0_8);
            // loadOverlayAtAddress((u32) o2_ROM_START, func_801A9160, (u32) temp_s0_8);
            // bzero(&D_801CF9F0, (u32) &func_801DC8D0 - (u32) &D_801CF9F0);
            // var_s2_18 = func_801F74E0;
            // var_s1_18 = code_943580_ROM_START;
            // var_s0_21 = code_944550_ROM_START - code_943580_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_21);
            // var_v0_19 = (u32) var_s0_21 > 0x17FFFU;
            // if (var_s0_21 != 0) {
            //     do {
            //         if (var_v0_19 == 0) {
            //             dmaOverlay((u32) var_s1_18, var_s2_18, (u32) var_s0_21);
            //             var_s0_21 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_18, var_s2_18, 0x18000U);
            //             var_s0_21 += 0xFFFE8000;
            //             var_s1_18 += 0x18000;
            //             var_s2_18 += 0x18000;
            //         }
            //         var_v0_19 = (u32) var_s0_21 > 0x17FFFU;
            //     } while (var_s0_21 != 0);
            // }
            // bzero(&D_801F84B0, &D_801F85C0 - &D_801F84B0);
            func_801F7680();
            var_a0 = D_801F81D8;
            func_80110610(var_a0);
            func_80110730();
            break;
        case 0x6E:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(7);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o7);
            // var_s2_19 = func_801DC8D0;
            // var_s1_19 = o7_ROM_START;
            // var_s0_22 = o8_ROM_START - o7_ROM_START;
            // osInvalICache(func_801DC8D0, var_s0_22);
            // var_v0_20 = (u32) var_s0_22 > 0x17FFFU;
            // if (var_s0_22 != 0) {
            //     do {
            //         if (var_v0_20 == 0) {
            //             dmaOverlay((u32) var_s1_19, var_s2_19, (u32) var_s0_22);
            //             var_s0_22 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_19, var_s2_19, 0x18000U);
            //             var_s0_22 += 0xFFFE8000;
            //             var_s1_19 += 0x18000;
            //             var_s2_19 += 0x18000;
            //         }
            //         var_v0_20 = (u32) var_s0_22 > 0x17FFFU;
            //     } while (var_s0_22 != 0);
            // }
            // bzero(&D_801FA360, (u32) &func_802036B0 - (u32) &D_801FA360);
            switch (D_801887D8) {
                case 0xB:
                case 0xC:
                case 0xD:
                    LOAD_OVERLAY(o8);
                    break;
                case 0xE:
                case 0xF:
                case 0x10:
                    LOAD_OVERLAY(o37);
                    break;
                case 0x28:
                    LOAD_OVERLAY(o22);
                    break;
                case 0x27:
                case 0x29:
                    LOAD_OVERLAY(o44);
                    break;
                case 0x14:
                case 0x15:
                case 0x16:
                case 0x17:
                case 0x3D:
                case 0x3E:
                case 0x3F:
                    LOAD_OVERLAY(o9);
                    break;
                case 0x4E:
                case 0x4F:
                case 0x50:
                    LOAD_OVERLAY(o26);
                    break;
                case 0x5A:
                    LOAD_OVERLAY(o29);
                    break;
                case 0x49:
                case 0x4D:
                    LOAD_OVERLAY(o46);
                    break;
                case 0x2D:
                case 0x2E:
                    LOAD_OVERLAY(o10);
                    break;
                case 0x2F:
                case 0x30:
                    LOAD_OVERLAY(o33);
                    break;
                case 0x2A:
                case 0x2B:
                case 0x4B:
                case 0x4C:
                    LOAD_OVERLAY(o28);
                    break;
                case 0x18:
                case 0x19:
                case 0x3A:
                case 0x3B:
                case 0x3C:
                    LOAD_OVERLAY(o23);
                    break;
                case 0x46:
                case 0x47:
                    LOAD_OVERLAY(o31);
                    break;
                case 0x51:
                case 0x53:
                    LOAD_OVERLAY(o11);
                    break;
                case 0x52:
                    LOAD_OVERLAY(o38);
                    break;
                case 0x1E:
                    LOAD_OVERLAY(o12);
                    break;
                case 0x1F:
                case 0x20:
                    LOAD_OVERLAY(o39);
                    break;
                case 0x1:
                case 0x2:
                case 0x3:
                    LOAD_OVERLAY(o27);
                    break;
                case 0x4:
                case 0x5:
                    LOAD_OVERLAY(o45);
                    break;
                case 0x31:
                case 0x32:
                    LOAD_OVERLAY(o13);
                    break;
                case 0x33:
                    LOAD_OVERLAY(o34);
                    break;
                case 0x37:
                case 0x38:
                    LOAD_OVERLAY(o14);
                    break;
                case 0x39:
                    LOAD_OVERLAY(o40);
                    break;
                case 0x11:
                case 0x12:
                case 0x13:
                    LOAD_OVERLAY(o15);
                    break;
                case 0x40:
                case 0x41:
                case 0x42:
                    LOAD_OVERLAY(o35);
                    break;
                case 0x34:
                    LOAD_OVERLAY(o16);
                    break;
                case 0x35:
                case 0x36:
                    LOAD_OVERLAY(o41);
                    break;
                case 0x48:
                case 0x4A:
                    LOAD_OVERLAY(o17);
                    break;
                case 0x57:
                    LOAD_OVERLAY(o30);
                    break;
                case 0x58:
                case 0x59:
                    LOAD_OVERLAY(o47);
                    break;
                case 0x1A:
                case 0x2C:
                    LOAD_OVERLAY(o18);
                    break;
                case 0x54:
                    LOAD_OVERLAY(o36);
                    break;
                case 0x55:
                case 0x56:
                    LOAD_OVERLAY(o48);
                    break;
                case 0x1B:
                case 0x1C:
                    LOAD_OVERLAY(o19);
                    break;
                case 0x1D:
                    LOAD_OVERLAY(o42);
                    break;
                case 0x43:
                case 0x44:
                case 0x45:
                    LOAD_OVERLAY(o20);
                    break;
                case 0x24:
                    LOAD_OVERLAY(o21);
                    break;
                case 0x25:
                case 0x26:
                    LOAD_OVERLAY(o43);
                    break;
                case 0x21:
                case 0x22:
                case 0x23:
                    LOAD_OVERLAY(o24);
                    break;
                case 0x7:
                case 0x8:
                case 0xA:
                    LOAD_OVERLAY(o25);
                    break;
                case 0x6:
                case 0x9:
                    LOAD_OVERLAY(o32);
                    break;
            }
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x6F:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(0xCC);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o7);
            LOAD_OVERLAY(o49);
            // var_s2_61 = func_801DC8D0;
            // var_s1_61 = o7_ROM_START;
            // var_s0_64 = o8_ROM_START - o7_ROM_START;
            // osInvalICache(func_801DC8D0, var_s0_64);
            // var_v0_62 = (u32) var_s0_64 > 0x17FFFU;
            // if (var_s0_64 != 0) {
            //     do {
            //         if (var_v0_62 == 0) {
            //             dmaOverlay((u32) var_s1_61, var_s2_61, (u32) var_s0_64);
            //             var_s0_64 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_61, var_s2_61, 0x18000U);
            //             var_s0_64 += 0xFFFE8000;
            //             var_s1_61 += 0x18000;
            //             var_s2_61 += 0x18000;
            //         }
            //         var_v0_62 = (u32) var_s0_64 > 0x17FFFU;
            //     } while (var_s0_64 != 0);
            // }
            // bzero(&D_801FA360, (u32) &func_802036B0 - (u32) &D_801FA360);
            // var_s2_62 = func_802036B0;
            // var_s1_62 = o49_ROM_START;
            // var_s0_65 = o50_ROM_START - o49_ROM_START;
            // osInvalICache(func_802036B0, var_s0_65);
            // var_v0_63 = (u32) var_s0_65 > 0x17FFFU;
            // if (var_s0_65 != 0) {
            //     do {
            //         if (var_v0_63 == 0) {
            //             dmaOverlay((u32) var_s1_62, var_s2_62, (u32) var_s0_65);
            //             var_s0_65 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_62, var_s2_62, 0x18000U);
            //             var_s0_65 += 0xFFFE8000;
            //             var_s1_62 += 0x18000;
            //             var_s2_62 += 0x18000;
            //         }
            //         var_v0_63 = (u32) var_s0_65 > 0x17FFFU;
            //     } while (var_s0_65 != 0);
            // }
            // bzero(&D_80204990, (s32) &D_80204990 * 0);
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x1C2:
            D_80174374 = -1;
            func_801001E4();
            func_800171CC(&D_80157150);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o56);
            // var_s2_63 = func_801F74E0;
            // var_s1_63 = o56_ROM_START;
            // var_s0_66 = o57_ROM_START - o56_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_66);
            // var_v0_64 = (u32) var_s0_66 > 0x17FFFU;
            // if (var_s0_66 != 0) {
            //     do {
            //         if (var_v0_64 == 0) {
            //             dmaOverlay((u32) var_s1_63, var_s2_63, (u32) var_s0_66);
            //             var_s0_66 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_63, var_s2_63, 0x18000U);
            //             var_s0_66 += 0xFFFE8000;
            //             var_s1_63 += 0x18000;
            //             var_s2_63 += 0x18000;
            //         }
            //         var_v0_64 = (u32) var_s0_66 > 0x17FFFU;
            //     } while (var_s0_66 != 0);
            // }
            // bzero(&D_80202A50, &D_80202A90 - &D_80202A50);
            func_801F74E0();
            func_801A9664();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0xC8:
            D_80174374 = -1;
            D_80187950 = 0x23F0;
            var_s1_64 = temp_s6;
            func_801001E4();
            func_801DC8D0(0x1F4);
            LOAD_OVERLAY(o3);
            LOAD_OVERLAY(o57);
            // var_s0_67 = func_801DC8D0;
            // osInvalICache(func_801DC8D0, temp_s6);
            // var_s2_64 = o3_ROM_START;
            // if (temp_s6 != 0) {
            //     var_v0_65 = (u32) var_s1_64 > 0x17FFFU;
            //     do {
            //         if (var_v0_65 == 0) {
            //             dmaOverlay((u32) var_s2_64, var_s0_67, (u32) var_s1_64);
            //             var_s1_64 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_64, var_s0_67, 0x18000U);
            //             var_s1_64 += 0xFFFE8000;
            //             var_s2_64 += 0x18000;
            //             var_s0_67 += 0x18000;
            //         }
            //         var_v0_65 = (u32) var_s1_64 > 0x17FFFU;
            //     } while (var_s1_64 != 0);
            // }
            // bzero(&D_801F7420, (u32) &func_801F74E0 - (u32) &D_801F7420);
            // var_s2_65 = func_801F74E0;
            // var_s1_65 = o57_ROM_START;
            // var_s0_68 = o58_ROM_START - o57_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_68);
            // var_v0_66 = (u32) var_s0_68 > 0x17FFFU;
            // if (var_s0_68 != 0) {
            //     do {
            //         if (var_v0_66 == 0) {
            //             dmaOverlay((u32) var_s1_65, var_s2_65, (u32) var_s0_68);
            //             var_s0_68 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_65, var_s2_65, 0x18000U);
            //             var_s0_68 += 0xFFFE8000;
            //             var_s1_65 += 0x18000;
            //             var_s2_65 += 0x18000;
            //         }
            //         var_v0_66 = (u32) var_s0_68 > 0x17FFFU;
            //     } while (var_s0_68 != 0);
            // }
            // bzero(&D_801FD880, &D_801FE1E0 - &D_801FD880);
            func_801F74E0();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0xC9:
            D_80174374 = -1;
            D_80187950 = 0x23F0;
            func_801001E4();
            func_801DC8D0(0x1F5);
            LOAD_OVERLAY(o59);
            // var_s2_66 = func_801F74E0;
            // var_s1_66 = o59_ROM_START;
            // var_s0_69 = o60_ROM_START - o59_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_69);
            // var_v0_67 = (u32) var_s0_69 > 0x17FFFU;
            // if (var_s0_69 != 0) {
            //     do {
            //         if (var_v0_67 == 0) {
            //             dmaOverlay((u32) var_s1_66, var_s2_66, (u32) var_s0_69);
            //             var_s0_69 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_66, var_s2_66, 0x18000U);
            //             var_s0_69 += 0xFFFE8000;
            //             var_s1_66 += 0x18000;
            //             var_s2_66 += 0x18000;
            //         }
            //         var_v0_67 = (u32) var_s0_69 > 0x17FFFU;
            //     } while (var_s0_69 != 0);
            // }
            // bzero(&D_801F7750, (s32) &D_801F7750 * 0);
            func_801F74E0();
            func_80013D60(0);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o58);
            // var_s2_67 = func_801F74E0;
            // var_s1_67 = o58_ROM_START;
            // var_s0_70 = o59_ROM_START - o58_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_70);
            // var_v0_68 = (u32) var_s0_70 > 0x17FFFU;
            // if (var_s0_70 != 0) {
            //     do {
            //         if (var_v0_68 == 0) {
            //             dmaOverlay((u32) var_s1_67, var_s2_67, (u32) var_s0_70);
            //             var_s0_70 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_67, var_s2_67, 0x18000U);
            //             var_s0_70 += 0xFFFE8000;
            //             var_s1_67 += 0x18000;
            //             var_s2_67 += 0x18000;
            //         }
            //         var_v0_68 = (u32) var_s0_70 > 0x17FFFU;
            //     } while (var_s0_70 != 0);
            // }
            // bzero(&D_801FC200, &D_80208220 - &D_801FC200);
            func_801F7A30();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0xCA:
            D_80174374 = -1;
            D_80187950 = 0x2404;
            var_s0_71 = 0xF;
            func_801001E4();
            var_v0_69 = &D_80175870 + 0x3C;
            do {
                *var_v0_69 = NULL;
                var_s0_71 -= 1;
                var_v0_69 -= 4;
            } while (var_s0_71 >= 0);
            *(&D_80175870 + 0x18) = D_80184504 + 0x1FA;
            D_8018903C = (s32) D_80184524;
            func_801DC8D0(0x1F6);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o60);
            // var_s1_68 = func_801F74E0;
            // var_s2_68 = o60_ROM_START;
            // var_s0_72 = o61_ROM_START - o60_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_72);
            // var_v0_70 = (u32) var_s0_72 > 0x17FFFU;
            // if (var_s0_72 != 0) {
            //     do {
            //         if (var_v0_70 == 0) {
            //             dmaOverlay((u32) var_s2_68, var_s1_68, (u32) var_s0_72);
            //             var_s0_72 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_68, var_s1_68, 0x18000U);
            //             var_s0_72 += 0xFFFE8000;
            //             var_s2_68 += 0x18000;
            //             var_s1_68 += 0x18000;
            //         }
            //         var_v0_70 = (u32) var_s0_72 > 0x17FFFU;
            //     } while (var_s0_72 != 0);
            // }
            // bzero(&D_801FAD10, &D_801FAD20 - &D_801FAD10);
            func_801F74E0();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0xCB:
            D_80174374 = -1;
            var_s0_73 = 0xF;
            func_801001E4();
            func_80014BF0();
            var_v0_71 = &D_80175870 + 0x3C;
            do {
                *var_v0_71 = NULL;
                var_s0_73 -= 1;
                var_v0_71 -= 4;
            } while (var_s0_73 >= 0);
            func_801DC8D0(0x1F7);
            if (D_80184504 == 0) {
                func_8001D520();
            } else {
                func_8001D738();
            }
            D_80187950 = 0x240E;
            D_8018903C = D_80184504 + 0x240E;
            func_8001CD1C();
            *(&D_80175870 + 0x18) = D_80184504 + 0x1FA;
            func_80013D60(1);
            func_8001F1F0(1);
            func_8001F144(&D_80157160);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o61);
            // var_s2_69 = o61_ROM_START;
            // var_s1_69 = func_801F74E0;
            // var_s0_74 = o62_ROM_START - o61_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_74);
            // var_v0_72 = (u32) var_s0_74 > 0x17FFFU;
            // if (var_s0_74 != 0) {
            //     do {
            //         if (var_v0_72 == 0) {
            //             dmaOverlay((u32) var_s2_69, var_s1_69, (u32) var_s0_74);
            //             var_s0_74 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_69, var_s1_69, 0x18000U);
            //             var_s0_74 += 0xFFFE8000;
            //             var_s2_69 += 0x18000;
            //             var_s1_69 += 0x18000;
            //         }
            //         var_v0_72 = (u32) var_s0_74 > 0x17FFFU;
            //     } while (var_s0_74 != 0);
            // }
            // bzero(&D_801F8FE0, &D_801FA170 - &D_801F8FE0);
            func_801A9664();
            func_801F74E0();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0xCC:
            D_80174374 = -1;
            D_80187950 = 0x240E;
            func_801001E4();
            func_80014BF0();
            func_801DC8D0(0x1F8);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o62);
            // var_s2_70 = func_801F74E0;
            // var_s1_70 = o62_ROM_START;
            // var_s0_75 = o63_ROM_START - o62_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_75);
            // var_v0_73 = (u32) var_s0_75 > 0x17FFFU;
            // if (var_s0_75 != 0) {
            //     do {
            //         if (var_v0_73 == 0) {
            //             dmaOverlay((u32) var_s1_70, var_s2_70, (u32) var_s0_75);
            //             var_s0_75 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_70, var_s2_70, 0x18000U);
            //             var_s0_75 += 0xFFFE8000;
            //             var_s1_70 += 0x18000;
            //             var_s2_70 += 0x18000;
            //         }
            //         var_v0_73 = (u32) var_s0_75 > 0x17FFFU;
            //     } while (var_s0_75 != 0);
            // }
            // bzero(&D_801F7DC0, &D_801F7E50 - &D_801F7DC0);
            func_801A9664();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x12C:
            D_80174374 = -1;
            func_801001E4();
            func_80014BF0();
            D_80187928 = 0;
            D_80175D98 = 0;
            D_80184308 = 0;
            func_801DC8D0(0x12C);
            D_8018903C = 0xC;
            func_8001CD1C();
            LOAD_OVERLAY(o2);
            LOAD_OVERLAY(o3);
            LOAD_OVERLAY(code_927C30);
            // var_s2_71 = func_801A9160;
            // var_s1_71 = o2_ROM_START;
            // var_s0_76 = o3_ROM_START - o2_ROM_START;
            // osInvalICache(func_801A9160, var_s0_76);
            // var_v0_74 = (u32) var_s0_76 > 0x17FFFU;
            // if (var_s0_76 != 0) {
            //     do {
            //         if (var_v0_74 == 0) {
            //             dmaOverlay((u32) var_s1_71, var_s2_71, (u32) var_s0_76);
            //             var_s0_76 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_71, var_s2_71, 0x18000U);
            //             var_s0_76 += 0xFFFE8000;
            //             var_s1_71 += 0x18000;
            //             var_s2_71 += 0x18000;
            //         }
            //         var_v0_74 = (u32) var_s0_76 > 0x17FFFU;
            //     } while (var_s0_76 != 0);
            // }
            // bzero(&D_801CF9F0, (u32) &func_801DC8D0 - (u32) &D_801CF9F0);
            // var_s0_77 = func_801DC8D0;
            // osInvalICache(func_801DC8D0, temp_s6);
            // var_s2_72 = o3_ROM_START;
            // var_s1_72 = temp_s6;
            // if (temp_s6 != 0) {
            //     var_v0_75 = (u32) var_s1_72 > 0x17FFFU;
            //     do {
            //         if (var_v0_75 == 0) {
            //             dmaOverlay((u32) var_s2_72, var_s0_77, (u32) var_s1_72);
            //             var_s1_72 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_72, var_s0_77, 0x18000U);
            //             var_s1_72 += 0xFFFE8000;
            //             var_s2_72 += 0x18000;
            //             var_s0_77 += 0x18000;
            //         }
            //         var_v0_75 = (u32) var_s1_72 > 0x17FFFU;
            //     } while (var_s1_72 != 0);
            // }
            // bzero(&D_801F7420, (u32) &func_801F74E0 - (u32) &D_801F7420);
            // var_s2_73 = func_801DC8D0;
            // var_s1_73 = code_927C30_ROM_START;
            // var_s0_78 = code_932A50_ROM_START - code_927C30_ROM_START;
            // osInvalICache(func_801DC8D0, var_s0_78);
            // var_v0_76 = (u32) var_s0_78 > 0x17FFFU;
            // if (var_s0_78 != 0) {
            //     do {
            //         if (var_v0_76 == 0) {
            //             dmaOverlay((u32) var_s1_73, var_s2_73, (u32) var_s0_78);
            //             var_s0_78 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_73, var_s2_73, 0x18000U);
            //             var_s0_78 += 0xFFFE8000;
            //             var_s1_73 += 0x18000;
            //             var_s2_73 += 0x18000;
            //         }
            //         var_v0_76 = (u32) var_s0_78 > 0x17FFFU;
            //     } while (var_s0_78 != 0);
            // }
            // bzero(&D_801E76F0, &D_801F6830 - &D_801E76F0);
            func_801E2B40();
            func_80110610(D_801E6290);
            func_80110730();
            break;
        case 0x12D:
            D_80174374 = -1;
            func_801001E4();
            func_80014BF0();
            D_80187928 = 0;
            D_80175D98 = 0;
            D_80184308 = 0;
            func_801DC8D0(0x12D);
            D_8018903C = 0xC;
            func_8001CD1C();
            LOAD_OVERLAY(o3);
            LOAD_OVERLAY(o63);
            // var_s0_79 = func_801DC8D0;
            // osInvalICache(func_801DC8D0, temp_s6);
            // var_s2_74 = o3_ROM_START;
            // var_s1_74 = temp_s6;
            // if (temp_s6 != 0) {
            //     var_v0_77 = (u32) var_s1_74 > 0x17FFFU;
            //     do {
            //         if (var_v0_77 == 0) {
            //             dmaOverlay((u32) var_s2_74, var_s0_79, (u32) var_s1_74);
            //             var_s1_74 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_74, var_s0_79, 0x18000U);
            //             var_s1_74 += 0xFFFE8000;
            //             var_s2_74 += 0x18000;
            //             var_s0_79 += 0x18000;
            //         }
            //         var_v0_77 = (u32) var_s1_74 > 0x17FFFU;
            //     } while (var_s1_74 != 0);
            // }
            // bzero(&D_801F7420, (u32) &func_801F74E0 - (u32) &D_801F7420);
            // var_s2_75 = func_801F74E0;
            // var_s1_75 = o63_ROM_START;
            // var_s0_80 = o64_ROM_START - o63_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_80);
            // var_v0_78 = (u32) var_s0_80 > 0x17FFFU;
            // if (var_s0_80 != 0) {
            //     do {
            //         if (var_v0_78 == 0) {
            //             dmaOverlay((u32) var_s1_75, var_s2_75, (u32) var_s0_80);
            //             var_s0_80 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_75, var_s2_75, 0x18000U);
            //             var_s0_80 += 0xFFFE8000;
            //             var_s1_75 += 0x18000;
            //             var_s2_75 += 0x18000;
            //         }
            //         var_v0_78 = (u32) var_s0_80 > 0x17FFFU;
            //     } while (var_s0_80 != 0);
            // }
            // bzero(&D_801F9850, &D_801F9860 - &D_801F9850);
            func_801A9664();
            func_801F8410();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x12E:
            D_80174374 = -1;
            var_s0_81 = 0xF;
            func_801001E4();
            func_80014BF0();
            D_80187928 = 0;
            D_80175D98 = 0;
            D_80184308 = 0;
            func_801DC8D0(0x12E);
            var_v0_79 = &D_80175870 + 0x3C;
            do {
                *var_v0_79 = NULL;
                var_s0_81 -= 1;
                var_v0_79 -= 4;
            } while (var_s0_81 >= 0);
            LOAD_OVERLAY(o3);
            LOAD_OVERLAY(o64);
            // var_s2_76 = o3_ROM_START;
            // var_s0_82 = temp_s6;
            // *(&D_80175870 + 0x18) = (void *) *(&D_80184F34 + (D_80152BFE * 0x5C));
            // var_s1_76 = func_801DC8D0;
            // func_80013C90();
            // osInvalICache(func_801DC8D0, temp_s6);
            // if (temp_s6 != 0) {
            //     var_v0_80 = (u32) var_s0_82 > 0x17FFFU;
            //     do {
            //         if (var_v0_80 == 0) {
            //             dmaOverlay((u32) var_s2_76, var_s1_76, (u32) var_s0_82);
            //             var_s0_82 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_76, var_s1_76, 0x18000U);
            //             var_s0_82 += 0xFFFE8000;
            //             var_s2_76 += 0x18000;
            //             var_s1_76 += 0x18000;
            //         }
            //         var_v0_80 = (u32) var_s0_82 > 0x17FFFU;
            //     } while (var_s0_82 != 0);
            // }
            // bzero(&D_801F7420, (u32) &func_801F74E0 - (u32) &D_801F7420);
            // var_s2_77 = func_801F74E0;
            // var_s1_77 = o64_ROM_START;
            // var_s0_83 = o65_ROM_START - o64_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_83);
            // var_v0_81 = (u32) var_s0_83 > 0x17FFFU;
            // if (var_s0_83 != 0) {
            //     do {
            //         if (var_v0_81 == 0) {
            //             dmaOverlay((u32) var_s1_77, var_s2_77, (u32) var_s0_83);
            //             var_s0_83 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_77, var_s2_77, 0x18000U);
            //             var_s0_83 += 0xFFFE8000;
            //             var_s1_77 += 0x18000;
            //             var_s2_77 += 0x18000;
            //         }
            //         var_v0_81 = (u32) var_s0_83 > 0x17FFFU;
            //     } while (var_s0_83 != 0);
            // }
            // bzero(&D_801FA210, &D_801FA420 - &D_801FA210);
            func_801A9664();
            func_801F91EC();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x12F:
            D_80174374 = -1;
            var_s0_84 = 0xF;
            func_801001E4();
            func_80014BF0();
            D_80187928 = 0;
            D_80175D98 = 0;
            D_80184308 = 0;
            func_801DC8D0(-1);
            var_v0_82 = &D_80175870 + 0x3C;
            do {
                *var_v0_82 = NULL;
                var_s0_84 -= 1;
                var_v0_82 -= 4;
            } while (var_s0_84 >= 0);
            var_s0_85 = 0;
            var_s1_78 = &D_80175870 + 0x1C;
            *(&D_80175870 + 0x18) = D_80184504 + 0x1FA;
            do {
                temp_v0 = guRandom() % 500;
                *var_s1_78 = temp_v0 + 1;
                if ((u32) (temp_v0 - 0x1E1) < 2U) {
                    *var_s1_78 = (void *)0x1A1;
                }
                var_s0_85 += 1;
                var_s1_78 += 4;
            } while (var_s0_85 < 4);
            func_80013D60(1);
            LOAD_OVERLAY(o2);
            LOAD_OVERLAY(o3);
            LOAD_OVERLAY(code_932A50);
            // var_s0_86 = func_801A9160;
            // var_s2_78 = o2_ROM_START;
            // var_s1_79 = o3_ROM_START - o2_ROM_START;
            // osInvalICache(func_801A9160, var_s1_79);
            // var_v0_83 = (u32) var_s1_79 > 0x17FFFU;
            // if (var_s1_79 != 0) {
            //     do {
            //         if (var_v0_83 == 0) {
            //             dmaOverlay((u32) var_s2_78, var_s0_86, (u32) var_s1_79);
            //             var_s1_79 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_78, var_s0_86, 0x18000U);
            //             var_s1_79 += 0xFFFE8000;
            //             var_s2_78 += 0x18000;
            //             var_s0_86 += 0x18000;
            //         }
            //         var_v0_83 = (u32) var_s1_79 > 0x17FFFU;
            //     } while (var_s1_79 != 0);
            // }
            // bzero(&D_801CF9F0, (u32) &func_801DC8D0 - (u32) &D_801CF9F0);
            // var_s0_87 = func_801DC8D0;
            // osInvalICache(func_801DC8D0, temp_s6);
            // var_s2_79 = o3_ROM_START;
            // var_s1_80 = temp_s6;
            // if (temp_s6 != 0) {
            //     var_v0_84 = (u32) var_s1_80 > 0x17FFFU;
            //     do {
            //         if (var_v0_84 == 0) {
            //             dmaOverlay((u32) var_s2_79, var_s0_87, (u32) var_s1_80);
            //             var_s1_80 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_79, var_s0_87, 0x18000U);
            //             var_s1_80 += 0xFFFE8000;
            //             var_s2_79 += 0x18000;
            //             var_s0_87 += 0x18000;
            //         }
            //         var_v0_84 = (u32) var_s1_80 > 0x17FFFU;
            //     } while (var_s1_80 != 0);
            // }
            // bzero(&D_801F7420, (u32) &func_801F74E0 - (u32) &D_801F7420);
            // var_s2_80 = func_801F74E0;
            // var_s1_81 = code_932A50_ROM_START;
            // var_s0_88 = code_935040_ROM_START - code_932A50_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_88);
            // var_v0_85 = (u32) var_s0_88 > 0x17FFFU;
            // if (var_s0_88 != 0) {
            //     do {
            //         if (var_v0_85 == 0) {
            //             dmaOverlay((u32) var_s1_81, var_s2_80, (u32) var_s0_88);
            //             var_s0_88 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_81, var_s2_80, 0x18000U);
            //             var_s0_88 += 0xFFFE8000;
            //             var_s1_81 += 0x18000;
            //             var_s2_80 += 0x18000;
            //         }
            //         var_v0_85 = (u32) var_s0_88 > 0x17FFFU;
            //     } while (var_s0_88 != 0);
            // }
            // bzero(&D_801F9AD0, &D_801F9AE0 - &D_801F9AD0);
            func_801F8370();
            func_80110610(D_801F8CA8);
            func_80110730();
            break;
        case 0x130:
            D_80174374 = -1;
            var_s0_89 = 0xF;
            func_801001E4();
            D_80187928 = 0;
            D_80175D98 = 0;
            D_80184308 = 0;
            func_80014BF0();
            var_v0_86 = &D_80175870 + 0x3C;
            do {
                *var_v0_86 = NULL;
                var_s0_89 -= 1;
                var_v0_86 -= 4;
            } while (var_s0_89 >= 0);
            if (D_80152C0C >= 0x13) {
                func_801DC8D0(2);
                *(&D_80175870 + 0x18) = (void *)0x1FA;
            } else {
                func_801DC8D0(-1);
                var_s0_90 = 0;
                var_a1_3 = &D_80175870 + 0x18;
                var_v1_3 = (D_80152C0C * 0x14) + &D_801880C8;
                do {
                    temp_v0_2 = *var_v1_3;
                    var_v1_3 += 4;
                    var_s0_90 += 1;
                    *var_a1_3 = temp_v0_2;
                    var_a1_3 += 4;
                } while (var_s0_90 < 5);
            }
            func_80013C90();
            LOAD_OVERLAY(o2);
            LOAD_OVERLAY(o3);
            LOAD_OVERLAY(code_932A50);
            // var_s0_91 = func_801A9160;
            // var_s2_81 = o2_ROM_START;
            // var_s1_82 = o3_ROM_START - o2_ROM_START;
            // osInvalICache(func_801A9160, var_s1_82);
            // var_v0_87 = (u32) var_s1_82 > 0x17FFFU;
            // if (var_s1_82 != 0) {
            //     do {
            //         if (var_v0_87 == 0) {
            //             dmaOverlay((u32) var_s2_81, var_s0_91, (u32) var_s1_82);
            //             var_s1_82 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_81, var_s0_91, 0x18000U);
            //             var_s1_82 += 0xFFFE8000;
            //             var_s2_81 += 0x18000;
            //             var_s0_91 += 0x18000;
            //         }
            //         var_v0_87 = (u32) var_s1_82 > 0x17FFFU;
            //     } while (var_s1_82 != 0);
            // }
            // bzero(&D_801CF9F0, (u32) &func_801DC8D0 - (u32) &D_801CF9F0);
            // var_s0_92 = func_801DC8D0;
            // osInvalICache(func_801DC8D0, temp_s6);
            // var_s2_82 = o3_ROM_START;
            // var_s1_83 = temp_s6;
            // if (temp_s6 != 0) {
            //     var_v0_88 = (u32) var_s1_83 > 0x17FFFU;
            //     do {
            //         if (var_v0_88 == 0) {
            //             dmaOverlay((u32) var_s2_82, var_s0_92, (u32) var_s1_83);
            //             var_s1_83 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_82, var_s0_92, 0x18000U);
            //             var_s1_83 += 0xFFFE8000;
            //             var_s2_82 += 0x18000;
            //             var_s0_92 += 0x18000;
            //         }
            //         var_v0_88 = (u32) var_s1_83 > 0x17FFFU;
            //     } while (var_s1_83 != 0);
            // }
            // bzero(&D_801F7420, (u32) &func_801F74E0 - (u32) &D_801F7420);
            // var_s2_83 = func_801F74E0;
            // var_s1_84 = code_932A50_ROM_START;
            // var_s0_93 = code_935040_ROM_START - code_932A50_ROM_START;
            // osInvalICache(func_801F74E0, var_s0_93);
            // var_v0_89 = (u32) var_s0_93 > 0x17FFFU;
            // if (var_s0_93 != 0) {
            //     do {
            //         if (var_v0_89 == 0) {
            //             dmaOverlay((u32) var_s1_84, var_s2_83, (u32) var_s0_93);
            //             var_s0_93 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_84, var_s2_83, 0x18000U);
            //             var_s0_93 += 0xFFFE8000;
            //             var_s1_84 += 0x18000;
            //             var_s2_83 += 0x18000;
            //         }
            //         var_v0_89 = (u32) var_s0_93 > 0x17FFFU;
            //     } while (var_s0_93 != 0);
            // }
            // bzero(&D_801F9AD0, &D_801F9AE0 - &D_801F9AD0);
            func_801F85B4();
            func_80110610(D_801F8CA8);
            func_80110730();
            break;
        case 0x131:
            D_80174374 = -1;
            func_801001E4();
            func_80014BF0();
            D_80187928 = 0;
            D_80175D98 = 0;
            D_80184308 = 0;
            func_801DC8D0(0x12C);
            D_8018903C = 0xC;
            func_8001CD1C();
            LOAD_OVERLAY(o2);
            LOAD_OVERLAY(o3);
            LOAD_OVERLAY(code_935040);
            // var_s2_84 = func_801A9160;
            // var_s1_85 = o2_ROM_START;
            // var_s0_94 = o3_ROM_START - o2_ROM_START;
            // osInvalICache(func_801A9160, var_s0_94);
            // var_v0_90 = (u32) var_s0_94 > 0x17FFFU;
            // if (var_s0_94 != 0) {
            //     do {
            //         if (var_v0_90 == 0) {
            //             dmaOverlay((u32) var_s1_85, var_s2_84, (u32) var_s0_94);
            //             var_s0_94 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_85, var_s2_84, 0x18000U);
            //             var_s0_94 += 0xFFFE8000;
            //             var_s1_85 += 0x18000;
            //             var_s2_84 += 0x18000;
            //         }
            //         var_v0_90 = (u32) var_s0_94 > 0x17FFFU;
            //     } while (var_s0_94 != 0);
            // }
            // bzero(&D_801CF9F0, (u32) &func_801DC8D0 - (u32) &D_801CF9F0);
            // var_s0_95 = func_801DC8D0;
            // osInvalICache(func_801DC8D0, temp_s6);
            // var_s2_85 = o3_ROM_START;
            // var_s1_86 = temp_s6;
            // if (temp_s6 != 0) {
            //     var_v0_91 = (u32) var_s1_86 > 0x17FFFU;
            //     do {
            //         if (var_v0_91 == 0) {
            //             dmaOverlay((u32) var_s2_85, var_s0_95, (u32) var_s1_86);
            //             var_s1_86 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_85, var_s0_95, 0x18000U);
            //             var_s1_86 += 0xFFFE8000;
            //             var_s2_85 += 0x18000;
            //             var_s0_95 += 0x18000;
            //         }
            //         var_v0_91 = (u32) var_s1_86 > 0x17FFFU;
            //     } while (var_s1_86 != 0);
            // }
            // bzero(&D_801F7420, (u32) &func_801F74E0 - (u32) &D_801F7420);
            // var_s2_86 = func_801DC8D0;
            // var_s1_87 = code_935040_ROM_START;
            // var_s0_96 = code_93C1D0_ROM_START - code_935040_ROM_START;
            // osInvalICache(func_801DC8D0, var_s0_96);
            // var_v0_92 = (u32) var_s0_96 > 0x17FFFU;
            // if (var_s0_96 != 0) {
            //     do {
            //         if (var_v0_92 == 0) {
            //             dmaOverlay((u32) var_s1_87, var_s2_86, (u32) var_s0_96);
            //             var_s0_96 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_87, var_s2_86, 0x18000U);
            //             var_s0_96 += 0xFFFE8000;
            //             var_s1_87 += 0x18000;
            //             var_s2_86 += 0x18000;
            //         }
            //         var_v0_92 = (u32) var_s0_96 > 0x17FFFU;
            //     } while (var_s0_96 != 0);
            // }
            // bzero(&D_801E3A60, &D_801F2B60 - &D_801E3A60);
            func_801E07B0();
            func_80110610(D_801E30A4);
            func_80110730();
            break;
        case 0x132:
            D_80174374 = -1;
            func_801001E4();
            func_80014BF0();
            D_80187928 = 0;
            D_80175D98 = 0;
            D_80184308 = 0;
            func_801DC8D0(0x12C);
            D_8018903C = 0xC;
            func_8001CD1C();
            LOAD_OVERLAY(o2);
            LOAD_OVERLAY(o3);
            LOAD_OVERLAY(code_927C30);
            // var_s2_87 = func_801A9160;
            // var_s1_88 = o2_ROM_START;
            // var_s0_97 = o3_ROM_START - o2_ROM_START;
            // osInvalICache(func_801A9160, var_s0_97);
            // var_v0_93 = (u32) var_s0_97 > 0x17FFFU;
            // if (var_s0_97 != 0) {
            //     do {
            //         if (var_v0_93 == 0) {
            //             dmaOverlay((u32) var_s1_88, var_s2_87, (u32) var_s0_97);
            //             var_s0_97 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_88, var_s2_87, 0x18000U);
            //             var_s0_97 += 0xFFFE8000;
            //             var_s1_88 += 0x18000;
            //             var_s2_87 += 0x18000;
            //         }
            //         var_v0_93 = (u32) var_s0_97 > 0x17FFFU;
            //     } while (var_s0_97 != 0);
            // }
            // bzero(&D_801CF9F0, (u32) &func_801DC8D0 - (u32) &D_801CF9F0);
            // var_s0_98 = func_801DC8D0;
            // osInvalICache(func_801DC8D0, temp_s6);
            // var_s2_88 = o3_ROM_START;
            // var_s1_89 = temp_s6;
            // if (var_s1_89 != 0) {
            //     var_v0_94 = (u32) var_s1_89 > 0x17FFFU;
            //     do {
            //         if (var_v0_94 == 0) {
            //             dmaOverlay((u32) var_s2_88, var_s0_98, (u32) var_s1_89);
            //             var_s1_89 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_88, var_s0_98, 0x18000U);
            //             var_s1_89 += 0xFFFE8000;
            //             var_s2_88 += 0x18000;
            //             var_s0_98 += 0x18000;
            //         }
            //         var_v0_94 = (u32) var_s1_89 > 0x17FFFU;
            //     } while (var_s1_89 != 0);
            // }
            // bzero(&D_801F7420, (u32) &func_801F74E0 - (u32) &D_801F7420);
            // var_s2_89 = func_801DC8D0;
            // var_s1_90 = code_927C30_ROM_START;
            // var_s0_99 = code_932A50_ROM_START - code_927C30_ROM_START;
            // osInvalICache(func_801DC8D0, var_s0_99);
            // var_v0_95 = (u32) var_s0_99 > 0x17FFFU;
            // if (var_s0_99 != 0) {
            //     do {
            //         if (var_v0_95 == 0) {
            //             dmaOverlay((u32) var_s1_90, var_s2_89, (u32) var_s0_99);
            //             var_s0_99 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s1_90, var_s2_89, 0x18000U);
            //             var_s0_99 += 0xFFFE8000;
            //             var_s1_90 += 0x18000;
            //             var_s2_89 += 0x18000;
            //         }
            //         var_v0_95 = (u32) var_s0_99 > 0x17FFFU;
            //     } while (var_s0_99 != 0);
            // }
            // bzero(&D_801E76F0, &D_801F6830 - &D_801E76F0);
            func_801E2D40();
            func_80110610(D_801E6290);
            func_80110730();
            break;
        case 0x133:
            D_80174374 = -1;
            var_s0_100 = 0xF;
            func_801001E4();
            func_80014BF0();
            var_v0_96 = &D_80175870 + 0x3C;
            D_80187928 = 0;
            D_80175D98 = 0;
            D_80184308 = 0;
            do {
                *var_v0_96 = NULL;
                var_s0_100 -= 1;
                var_v0_96 -= 4;
            } while (var_s0_100 >= 0);
            if (D_80152C14 < 5) {
                var_a0_4 = 0x12F;
            } else {
                var_a0_4 = 0x131;
                if (D_80152C14 == 5) {
                    var_a0_4 = 0x130;
                }
            }
            func_801DC8D0(var_a0_4);
            *(&D_80175870 + 0x18) = D_80184504 + 0x1FA;
            *(&D_80175870 + 0x1C) = (void *) *(&D_80184F34 + (D_80152BFE * 0x5C));
            LOAD_DATA_SEGMENT(data_55ECF0);
            // var_s0_101 = &D_801E0560;
            // var_s2_90 = data_55ECF0_ROM_START;
            // var_s1_91 = data_56BB50_ROM_START - data_55ECF0_ROM_START;
            // osInvalICache(&D_801E0560, var_s1_91);
            // var_v0_97 = (u32) var_s1_91 > 0x17FFFU;
            // if (var_s1_91 != 0) {
            //     do {
            //         if (var_v0_97 == 0) {
            //             dmaOverlay((u32) var_s2_90, var_s0_101, (u32) var_s1_91);
            //             var_s1_91 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_90, var_s0_101, 0x18000U);
            //             var_s1_91 += 0xFFFE8000;
            //             var_s2_90 += 0x18000;
            //             var_s0_101 += 0x18000;
            //         }
            //         var_v0_97 = (u32) var_s1_91 > 0x17FFFU;
            //     } while (var_s1_91 != 0);
            // }
            func_800171CC(&D_8015716C);
            switch (D_80152C14) {
            case 0:
                *(&D_80175870 + 0x20) = 0x1E2;
                break;
            case 1:
                *(&D_80175870 + 0x20) = 0x1E2;
                break;
            case 2:
                *(&D_80175870 + 0x20) = 0x1E2;
                break;
            case 3:
            case 4:
            case 6:
                *(&D_80175870 + 0x20) = 0x1E3;
                break;
            }
            func_80013C90();
            LOAD_OVERLAY(code_93C1D0);
            // var_s0_102 = func_801DC8D0;
            // var_s2_91 = code_93C1D0_ROM_START;
            // var_s1_92 = code_943580_ROM_START - code_93C1D0_ROM_START;
            // osInvalICache(func_801DC8D0, var_s1_92);
            // var_v0_99 = (u32) var_s1_92 > 0x17FFFU;
            // if (var_s1_92 != 0) {
            //     do {
            //         if (var_v0_99 == 0) {
            //             dmaOverlay((u32) var_s2_91, var_s0_102, (u32) var_s1_92);
            //             var_s1_92 = 0;
            //         } else {
            //             dmaOverlay((u32) var_s2_91, var_s0_102, 0x18000U);
            //             var_s1_92 += 0xFFFE8000;
            //             var_s2_91 += 0x18000;
            //             var_s0_102 += 0x18000;
            //         }
            //         var_v0_99 = (u32) var_s1_92 > 0x17FFFU;
            //     } while (var_s1_92 != 0);
            // }
            // bzero(&D_801E3C80, &D_801E7370 - &D_801E3C80);
            func_801E18E8();
            func_80110610(D_801E290C);
            func_80110730();
            break;
        }
        if (D_801883B0 != -1 && D_80188E74 != D_801883B0) {
            func_80105CB0(D_801883B0);
        }
        if (D_80174374 == -1) {
            do {

            } while (D_80174374 == -1);
        }
        func_80110700();
        temp_v0_3 = D_80174374;
        D_80174374 = -1;
        D_80171E98 = temp_v0_3;
        func_80110610(func_801003EC);
        func_80110730();
        while (D_80174374 == -1) {
        }
        func_80110700();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/DB50", mainproc);
#endif

const char D_8015AF0C[] = "9H";
extern void func_80110B10(void *, s32);
extern s32 D_801830C8[][4];
extern s32 D_801830D0[][4];
extern s32 D_801830D4[][4];
extern s32 D_801A90E0[];

void func_80104C38(s32 arg0) {
    func_80110B10(&D_801830C8[arg0], arg0);
    func_80110B10(&D_801830C8[arg0], arg0);
    if (D_801830D4[arg0][0] == 2) {
        D_801A90E0[arg0] = 300;
    } else {
        D_801A90E0[arg0] = D_801830D0[arg0][0];
    }
}

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104CE0);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104D3C);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104E48);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80104FD4);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80105164);

INCLUDE_ASM("asm/nonmatchings/DB50", func_80105364);

s32 abs(s32 value) {
    return (value < 0) ? -value : value;
}

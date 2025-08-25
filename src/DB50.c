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
extern u32 D_802085F0[];
extern u32 D_80208680[];
extern s32 D_80208DB0;
extern s32 func_801FCD80(void); //s32 func_o51_801FCD80_16D410(void)
extern s32 func_801FEDF0(void); //s32 func_o55_801FEDF0_188C80(void)
extern void func_802036B0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7); //void func_o19_802036B0_10E220(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7)

void mainproc(void *arg0) {
    s32 temp_v0;
    s32 var_a0_4;
    s32 var_s0;
    s32 var_s0_100;
    s32 var_s0_3;
    s32 var_s0_71;
    s32 var_s0_73;
    s32 var_s0_7;
    s32 var_s0_81;
    s32 var_s0_84;
    s32 var_s0_85;
    s32 var_s0_89;
    s32 var_s0_90;
   
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

    func_80110560();
    func_80110740();
    func_800FFF50();
    D_80174374 = 0;
    D_80188E74 = -1;
    D_801883B0 = -1;
    while (1) {
        switch (D_80174374) {
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
            func_801F81C0();
            func_80110610(D_801F8B14);
            func_80110730();
            break;
        default:  
            if (D_80174374 == 0x1C3) {
                var_s0_3 = 0xF;
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
                func_801F74E0();
                func_801A9664();
                func_80110610(D_801B53CC);
                func_80110730();
            }
            break;
        case 0x0: 
            D_80174374 = -1;
            LOAD_OVERLAY(o1);
            func_801A91E0();
            func_80110610(D_801AA5F4);
            func_80110730();
            break;
        case 0x1: 
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(2);
            LOAD_OVERLAY(code_926CF0);
            func_801A9160();
            func_80110610(D_801A9FB0);
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
            func_801F7B5C();
            func_80110610(D_801F9804);
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
            func_801A956C();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x1F:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(5);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o5);
            func_801A9664();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x20:
            D_80174374 = -1;
            LOAD_CODE_SEGMENT(o3);
            LOAD_CODE_SEGMENT(o4);
            D_80172008 = 0x2710;
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x21:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(1);
            LOAD_CODE_SEGMENT(o3);
            LOAD_CODE_SEGMENT(o4);
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x22:
            D_80174374 = -1;
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o6);
            func_801A9664();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x23:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(4);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o6);
            func_801A9664();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x24:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(6);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o7);
            func_801A9664();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x26:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(8);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o6);
            func_801A9664();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x27:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(9);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o6);
            func_801A9664();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x64:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(0xC8);
            LOAD_CODE_SEGMENT(o3);
            LOAD_CODE_SEGMENT(o4);
            func_801A9664();
            func_80110610(D_801B53CC);
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
            switch (D_80152B84) {
                default:
                    LOAD_OVERLAY(o51);
                    break;
                case 4: 
                    LOAD_OVERLAY(o55);
                    break;
                case 3: 
                    LOAD_OVERLAY(o52);
                    if (D_80152B8C < 0xFB) {
                        LOAD_DATA_SEGMENT(o53);
                        bzero(D_80208680,  D_80208680 - D_80208680);
                    } else {
                        LOAD_DATA_SEGMENT(o54);
                        bzero(D_802085F0,  D_802085F0 - D_802085F0);
                    }
                    break;
                }
            func_801A9664();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x2: 
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(0xCA);
            LOAD_CODE_SEGMENT(o2);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(code_943580);
            func_801F7680();
            func_80110610(D_801F81D8);
            func_80110730();
            break;
        case 0x6E:
            D_80174374 = -1;
            func_801001E4();
            func_801DC8D0(7);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o7);
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
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0x1C2:
            D_80174374 = -1;
            func_801001E4();
            func_800171CC(&D_80157150);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o56);
            func_801F74E0();
            func_801A9664();
            func_80110610(D_801B53CC);
            func_80110730();
            break;
        case 0xC8:
            D_80174374 = -1;
            D_80187950 = 0x23F0;
            func_801001E4();
            func_801DC8D0(0x1F4);
            LOAD_OVERLAY(o3);
            LOAD_OVERLAY(o57);
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
            func_801F74E0();
            func_80013D60(0);
            LOAD_CODE_SEGMENT(o3);
            LOAD_OVERLAY(o58);
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
            func_801E18E8();
            func_80110610(D_801E290C);
            func_80110730();
            break;
        }
        if (D_801883B0 != -1 && D_80188E74 != D_801883B0) {
            func_80105CB0(D_801883B0);
        }
        while (D_80174374 == -1) {
        }
        func_80110700();
        D_80171E98 = D_80174374;
        D_80174374 = -1;
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

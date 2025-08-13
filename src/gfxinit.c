#include "gfxinit.h"
#include "common.h"
#include "ultra64.h"

// The viewport z-range below is half of the max (511)
#define G_HALFZ (G_MAXZ / 2) /* 9 bits of integer screen-Z precision */
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

LookAt gfxLookAt[2];

static Vp vp = { {
    { SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, G_MAXZ / 2, 0 }, /* scale */
    { SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, G_MAXZ / 2, 0 }, /* translate */
} };

Lights1 D_801529A0 = gdSPDefLights1(101, 101, 101, 255, 255, 255, 73, 73, 73);

s32 D_801529B8[] = { 0x00000000, 0x00000000 };

Gfx D_801529C0[] = {
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_80152A38[] = {
    gsSPViewport(OS_K0_TO_PHYSICAL(&vp)),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                          G_SHADING_SMOOTH),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

void func_800FF7A0(s32 isOpaque) {
    D_80189064 = (Gfx *) ((D_801529B8[0] << 14) + &D_80189090); // TODO: Figure out what types these vars are

    gSPSegment(D_80189064++, 0, 0);
    gSPDisplayList(D_80189064++, OS_K0_TO_PHYSICAL(&D_80152A38));
    gSPDisplayList(D_80189064++, OS_K0_TO_PHYSICAL(&D_801529C0));
    gDPSetDepthImage(D_80189064++, OS_K0_TO_PHYSICAL(D_80171B20));
    gDPPipeSync(D_80189064++);
    gDPSetCycleType(D_80189064++, G_CYC_FILL);
    gDPSetColorImage(D_80189064++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_K0_TO_PHYSICAL(D_80171B20));
    gDPSetFillColor(D_80189064++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
    gDPFillRectangle(D_80189064++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    gDPPipeSync(D_80189064++);
    gDPSetColorImage(D_80189064++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(D_801880C0));
    if (isOpaque == TRUE) {
        gDPSetFillColor(D_80189064++, (GPACK_RGBA5551(0, 0, 0, 255) << 16) | GPACK_RGBA5551(0, 0, 0, 255));
        gDPFillRectangle(D_80189064++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    }
    gDPPipeSync(D_80189064++);
    gDPSetScissor(D_80189064++, G_SC_NON_INTERLACE, 0, 20, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 21);
    gDPPipeSync(D_80189064++);
}

#ifdef NON_EQUIVALENT
void func_80110434(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void __assert(const char *, const char *, int);
#define assert(EX) ((EX) ? ((void) 0) : __assert("EX", __FILE__, __LINE__))
extern s32 D_801529B8;
extern u32 D_80189090;

void func_800FF9D8(void) {
    u32 temp_v0_2;

    gDPFullSync(D_80189064++);
    gSPEndDisplayList(D_80189064++);

    temp_v0_2 = D_801529B8 << 0x10;
    if (((s32) ((D_80189064 - (u32) &D_80189090) - temp_v0_2) >> 3) >= 0x2000) {
        __assert("EX", "gfxinit.c", 116);
    }
    temp_v0_2 = D_801529B8 << 0x10;
    func_80110434(((temp_v0_2) + (u32) &D_80189090), ((s32) ((D_80189064 - (u32) &D_80189090) - temp_v0_2) >> 3) << 3,
                  2, 1);
    D_801529B8 = (D_801529B8 + 1) & 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/gfxinit", func_800FF9D8);
#endif

void func_800FFABC(Mtx *mtx, f32 arg1, f32 arg2) {
    u16 perspNorm;
    f64 angle;

    guOrtho(mtx, -320.0f, 320.0f, -240.0f, 240.0f, 0.1f, 100.0f, 1.0f);
    guPerspective(mtx, &perspNorm, 45.84f, 1.3333334f, 10.0f, 15000.0f, 1.0f);
    angle = (arg1 + 90.0) * (0.0174532919999999987); // M_DTOR
    guLookAtReflect((mtx + 1), gfxLookAt, 0.0f, cosf(angle) * arg2, sinf(angle) * arg2, 0.0f, 0.0f, 0.0f, 0.0f,
                    10000.0f, 0.0f);
    gSPPerspNormalize(D_80189064++, perspNorm);
    gSPLookAtX(D_80189064++, &gfxLookAt->l[0]);
    gSPLookAtY(D_80189064++, &gfxLookAt->l[1]);
    gSPMatrix(D_80189064++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(D_80189064++, (mtx + 1), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(D_80189064++, OS_K0_TO_PHYSICAL(&D_80126370), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    osWritebackDCache((mtx + 1), sizeof(Mtx));
    osWritebackDCache(mtx, sizeof(Mtx));
}

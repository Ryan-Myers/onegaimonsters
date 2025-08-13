#include "common.h"
#include "ultra64.h"

/**
   16×16 quadrant I atan2 lookup table
   Top-left (x=0, y=0) = 45 → corresponds to atan(0/0), but since 0/0 is undefined, it’s a special-case center value.
   Bottom-left (x=0, y=15) = 90 → corresponds to atan(y/x) where x=0, y>0 → 90°.
   Top-right (x=15, y=0) = 0 → corresponds to atan(0 / large x) = 0°.
   The values are in degrees scaled by 1 (not fixed point), and the function adds the quadrant offset (90, 180, 270) to
   get the full angle.
*/
u8 atan2_lookuptable[16][16] = {
    { 45, 18, 11, 8, 6, 5, 4, 3, 3, 3, 2, 2, 2, 1, 0, 0 },
    { 71, 45, 30, 23, 18, 15, 12, 11, 10, 8, 8, 7, 6, 6, 5, 5 },
    { 78, 59, 45, 35, 29, 24, 21, 18, 16, 14, 13, 12, 11, 10, 9, 9 },
    { 81, 66, 54, 45, 37, 32, 28, 25, 22, 20, 18, 16, 15, 14, 13, 12 },
    { 83, 71, 60, 52, 45, 39, 34, 30, 27, 25, 23, 21, 19, 18, 17, 16 },
    { 84, 74, 65, 57, 50, 45, 40, 36, 32, 30, 27, 25, 23, 22, 20, 19 },
    { 85, 77, 69, 61, 55, 49, 45, 40, 37, 34, 31, 29, 27, 25, 24, 22 },
    { 86, 78, 71, 65, 59, 53, 49, 45, 41, 38, 35, 33, 30, 29, 27, 25 },
    { 86, 80, 73, 67, 62, 57, 52, 48, 45, 41, 39, 36, 34, 32, 30, 28 },
    { 87, 81, 75, 70, 64, 60, 55, 51, 48, 45, 42, 39, 37, 35, 33, 31 },
    { 87, 82, 76, 71, 67, 62, 58, 54, 51, 48, 45, 42, 40, 38, 36, 34 },
    { 87, 82, 77, 73, 68, 64, 60, 57, 53, 50, 47, 45, 42, 40, 38, 36 },
    { 88, 83, 78, 74, 70, 66, 62, 59, 56, 52, 50, 47, 45, 43, 40, 39 },
    { 89, 83, 79, 75, 71, 67, 64, 61, 58, 55, 52, 49, 47, 45, 43, 41 },
    { 90, 84, 80, 76, 72, 69, 66, 62, 59, 56, 54, 51, 49, 47, 45, 43 },
    { 90, 84, 81, 77, 74, 70, 67, 64, 61, 58, 56, 53, 51, 49, 47, 45 },
};

// AI names as I don't know the math properly.
// Computes an angle in degrees from a 2D vector (treated as X,Z in 3D space)
f32 get_angle_from_xz(f32 x, f32 z) {
    f32 y = 0.0f; // Always 0 — we normalize in X,Z plane
    f32 angleDeg;

    // If vector is very short, scale it up
    if ((x * x) < 0.1 && (z * z) < 0.1) {
        x *= 2.0f;
        z *= 2.0f;
    } else {
        guNormalize(&x, &y, &z);
    }

    // Scale for lookup table index
    x *= 15.0f;
    z *= 15.0f;

    // Quadrant mapping
    if (x >= 0.0f) {
        if (z >= 0.0f) {
            angleDeg = (f32) atan2_lookuptable[(s32) x][(s32) z];
        } else {
            z = -z;
            angleDeg = (f32) atan2_lookuptable[(s32) z][(s32) x] + 90.0;
        }
    } else {
        if (z >= 0.0f) {
            x = -x;
            angleDeg = (f32) atan2_lookuptable[(s32) z][(s32) x] + 270.0;
        } else {
            x = -x;
            z = -z;
            angleDeg = (f32) atan2_lookuptable[(s32) x][(s32) z] + 180.0f;
        }
    }

    return angleDeg;
}

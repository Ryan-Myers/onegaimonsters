#include "common.h"
#include "1E8D0.h"

INCLUDE_ASM("asm/nonmatchings/1E8D0", func_80110CD0);

void set_company_game_code(u16 *companyCode, u32 *gameCode) {
    bcopy(companyCode, &gCompanyCode, 2);
    bcopy(gameCode, &gGameCode, 4);
}

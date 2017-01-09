#ifndef DOLPHIN_EMU_CTRANSFORM_H
#define DOLPHIN_EMU_CTRANSFORM_H

#include "game_value.h"

class CTransform : public game_value<0x4 * 3 * 4> {
public:
    CTransform(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    game_array<game_float, 0x12> matrix = game_array<game_float, 0x12>(ptr(), 0x0);
    game_array<game_u32, 0x12> rawMatrix = game_array<game_u32, 0x12>(ptr(), 0x0);
};


#endif //DOLPHIN_EMU_CTRANSFORM_H

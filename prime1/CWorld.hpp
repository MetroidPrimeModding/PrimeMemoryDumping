#ifndef PRIME_WATCH_DUMP_CWORLD_HPP
#define PRIME_WATCH_DUMP_CWORLD_HPP

#include "game_value.h"

class CWorld : public game_value<> {
public:
    CWorld(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    game_u32 phase = game_u32(ptr(), 0x4);
    game_u32 mlvlID = game_u32(ptr(), 0x8);
    game_u32 strgID = game_u32(ptr(), 0xC);
    game_u32 currentAreaID = game_u32(ptr(), 0x68);
};

#endif //PRIME_WATCH_DUMP_CWORLD_HPP

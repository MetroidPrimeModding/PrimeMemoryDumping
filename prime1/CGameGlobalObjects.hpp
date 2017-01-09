#ifndef PRIME_WATCH_DUMP_CGAMEGLOBALOBJECTS_HPP
#define PRIME_WATCH_DUMP_CGAMEGLOBALOBJECTS_HPP

#include "game_value.h"
#include "prime1/CGameState.hpp"

class CGameGlobalObjects : public game_value<> {
public:
    static constexpr uint32_t LOCATION = 0x80457798;
    CGameGlobalObjects(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    game_ptr<CGameState> gameState = game_ptr<CGameState>(ptr(), 0x134);
};

#endif //PRIME_WATCH_DUMP_CGAMEGLOBALOBJECTS_HPP

#ifndef PRIME_WATCH_DUMP_CSTATEMANAGER_HPP
#define PRIME_WATCH_DUMP_CSTATEMANAGER_HPP

#include "game_value.h"
#include "prime1/actors/CPlayer.hpp"
#include "prime1/CWorld.hpp"
#include "prime1/CPlayerState.hpp"

class CStateManager : public game_value<> {
public:
    static constexpr uint32_t LOCATION = 0x8045A1A8;
    CStateManager(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    game_ptr<CPlayer> player = game_ptr<CPlayer>(ptr(), 0x84C);
    game_ptr<CWorld> world = game_ptr<CWorld>(ptr(), 0x850);
    game_rc_ptr<CPlayerState> playerState = game_rc_ptr<CPlayerState>(ptr(), 0x8b8);
};

#endif //PRIME_WATCH_DUMP_CSTATEMANAGER_HPP

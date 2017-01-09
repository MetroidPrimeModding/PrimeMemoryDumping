#ifndef PRIME_WATCH_DUMP_CPLAYERGUN_H
#define PRIME_WATCH_DUMP_CPLAYERGUN_H

#include "game_value.h"

class CPlayerGun : public game_value<> {
public:
    CPlayerGun(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}


};

#endif //PRIME_WATCH_DUMP_CPLAYERGUN_H

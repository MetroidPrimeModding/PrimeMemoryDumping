#ifndef DOLPHIN_EMU_CENTITY_H
#define DOLPHIN_EMU_CENTITY_H

#include "game_value.h"

class CEntity : public game_value<> {
public:
    CEntity(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}
};


#endif //DOLPHIN_EMU_CENTITY_H

#ifndef DOLPHIN_EMU_CPLAYER_H
#define DOLPHIN_EMU_CPLAYER_H

#include "CPhysicsActor.h"

class CPlayer : public CPhysicsActor {
public:
    CPlayer(uint32_t base_ptr, uint32_t ptr_offset = 0) : CPhysicsActor(base_ptr, ptr_offset) {}
};


#endif //DOLPHIN_EMU_CPLAYER_H

#ifndef DOLPHIN_EMU_CPHYSICSACTOR_H
#define DOLPHIN_EMU_CPHYSICSACTOR_H

#include "CActor.h"

class CPhysicsActor : public CActor {
public:
    CPhysicsActor(uint32_t base_ptr, uint32_t ptr_offset = 0) : CActor(base_ptr, ptr_offset) {}

};


#endif //DOLPHIN_EMU_CPHYSICSACTOR_H

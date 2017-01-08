#ifndef DOLPHIN_EMU_CACTOR_H
#define DOLPHIN_EMU_CACTOR_H

#include "CEntity.h"
#include "prime1/CTransform.h"

class CActor : public CEntity {
public:
    CActor(uint32_t base_ptr, uint32_t ptr_offset = 0) : CEntity(base_ptr, ptr_offset) {}

    CTransform transform = CTransform(ptr(), 0x34);
};


#endif //DOLPHIN_EMU_CACTOR_H

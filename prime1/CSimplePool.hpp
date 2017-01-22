#ifndef PRIME_WATCH_DUMP_CSIMPLEPOOL_HPP
#define PRIME_WATCH_DUMP_CSIMPLEPOOL_HPP

#include "game_value.h"
#include "prime1/CRBTree.hpp"
#include "prime1/CPair.hpp"
#include "prime1/SObjectTag.hpp"
#include "prime1/CObjectReference.hpp"

class CSimplePool : public game_value<> {
public:
    CSimplePool(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    using ResourceType = CPair<SObjectTag, game_ptr<CObjectReference>>;

    CRBTree<ResourceType> resources = CRBTree<ResourceType>(ptr(), 0x8);
};


#endif //PRIME_WATCH_DUMP_CSIMPLEPOOL_HPP

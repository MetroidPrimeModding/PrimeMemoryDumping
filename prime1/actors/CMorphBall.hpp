#ifndef PRIME_WATCH_DUMP_CMORPHBALL_H
#define PRIME_WATCH_DUMP_CMORPHBALL_H

#include "game_value.h"
#include "prime1/CSpherePrimitive.hpp"

class CMorphBall : public game_value<> {
public:
    CMorphBall(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    CSpherePrimitive collisionPrimitive = CSpherePrimitive(ptr(), 0x38);

#ifdef PRIME_DUMP_JSON
    inline nlohmann::json json() {
      nlohmann::json res;
      nlohmann::json primitive;
      primitive["origin"] = collisionPrimitive.origin.json();
      primitive["radius"] = collisionPrimitive.radius.read();
      res["collision_primitive"] = primitive;
      return res;
    }
#endif
};

#endif //PRIME_WATCH_DUMP_CPLAYERGUN_H

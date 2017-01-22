#ifndef PRIME_WATCH_DUMP_COBJECTREFERENCE_HPP
#define PRIME_WATCH_DUMP_COBJECTREFERENCE_HPP

#include "game_value.h"
#include "prime1/SObjectTag.hpp"

class CObjectReference : public game_value<> {
public:
    CObjectReference(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    game_u16 refCount = game_u16(ptr(), 0x0);
    game_u16 lockCount = game_u16(ptr(), 0x2);
    game_u8 loading = game_u8(ptr(), 0x3); /* leftmost bit of lockCount */
    SObjectTag objTag = SObjectTag(ptr(), 0x4);
    game_u32 objectStore = game_u32(ptr(), 0xC);
    game_u32 object = game_u32(ptr(), 0x10);
//    IObjectStore* xC_objectStore = nullptr;
//    IObj* x10_object = nullptr;
//    CVParamTransfer x14_params;

    inline bool isLoading() {
      return (loading.read() & 0x8000) != 0;
    }

    inline nlohmann::json json() {
      nlohmann::json res;
      res["refCount"] = refCount.read();
      res["lockCount"] = lockCount.read() & 0x7FFF;
      res["loading"] = isLoading();
      res["objTag"] = objTag.json();
      res["objectStorePtr"] = objectStore.read();
      res["objectPtr"] = object.read();
      return res;
    }
};

#endif //PRIME_WATCH_DUMP_COBJECTREFERENCE_HPP

#ifndef PRIME_WATCH_DUMP_CVECTOR_HPP
#define PRIME_WATCH_DUMP_CVECTOR_HPP

#include "game_value.h"

template<class T>
class CVector : public game_value<> {
    static_assert(T::size > 0, "Attempting to create vector of an object with undefined size");
public:
    CVector(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    game_u32 size = game_u32(ptr(), 0x0);
    game_ptr<T> last = game_ptr<T>(ptr(), 0x4);
    game_ptr<T> end = game_ptr<T>(ptr(), 0x8);
    game_ptr<T> first = game_ptr<T>(ptr(), 0xC);

    inline T operator[](std::size_t idx) const {
      uint32_t count = size.read();
      assert(idx < count); // Error out in debug mode
      return game_ptr<T>(first.ptr(), (idx % count) * T::size); //In production, take the modulus and hope for the best
    }

    inline nlohmann::json json() {
      uint32_t count = size.read();
      std::vector<nlohmann::json> res;
      for (size_t i = 0; i < count; i++) {
        T ele = (*this)[i];
        res.push_back(ele.json());
      }
      return res;
    }
};

#endif //PRIME_WATCH_DUMP_CVECTOR_HPP

//
// Created by pwootage on 1/4/17.
//

#ifndef DOLPHIN_EMU_GAME_PTR_H
#define DOLPHIN_EMU_GAME_PTR_H

#include <cstdint>
#include <cassert>
#include "GameMemory.h"

#ifdef PRIME_DUMP_JSON
#include "json.hpp"
#endif

template<uint32_t valueSizeInBytes = 0x0>
class game_value {
public:
    static constexpr uint32_t size = valueSizeInBytes;

#ifdef BASE_OFFSET
    game_value(uint32_t base_ptr, uint32_t ptr_offset = 0) : base(base_ptr), offset(ptr_offset) {}

    inline uint32_t ptr() const {
      return base + offset;
    }

private:
    uint32_t base;
    uint32_t offset;
#else
    game_value(uint32_t base_ptr, uint32_t ptr_offset = 0) : addr(base_ptr + ptr_offset) {}

    inline uint32_t ptr() const {
      return addr;
    }

private:
    uint32_t addr;
#endif
};

class game_u8 : public game_value<1> {
public:
    game_u8(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value<1>(base_ptr, ptr_offset) {}

    inline uint8_t read() const {
      return static_cast<uint8_t>((GameMemory::read_u32(ptr()) >> 24) & 0xFF);
    }

    inline int8_t readSigned() const {
      return static_cast<int8_t>((GameMemory::read_u32(ptr()) >> 24) & 0xFF);
    }

#ifdef PRIME_DUMP_JSON
    inline nlohmann::json json() {
      return read();
    }
#endif
};

class game_u16 : public game_value<2> {
public:
    game_u16(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value<2>(base_ptr, ptr_offset) {}

    inline uint16_t read() const {
      return static_cast<uint16_t>((GameMemory::read_u32(ptr()) >> 16) & 0xFFFF);
    }

    inline int16_t readSigned() const {
      return static_cast<int16_t>((GameMemory::read_u32(ptr()) >> 16) & 0xFFFF);
    }

#ifdef PRIME_DUMP_JSON
    inline nlohmann::json json() {
      return read();
    }
#endif
};


class game_u32 : public game_value<4> {
public:
    game_u32(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    inline uint32_t read() const {
      return GameMemory::read_u32(ptr());
    }

#ifdef PRIME_DUMP_JSON
    inline nlohmann::json json() {
      return read();
    }
#endif
};

class game_float : public game_value<4> {
public:
    game_float(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    inline float read() const {
      return GameMemory::read_float(ptr());
    }

#ifdef PRIME_DUMP_JSON
    inline nlohmann::json json() {
      return read();
    }
#endif
};

class game_double : public game_value<8> {
public:
    game_double(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    inline double read() const {
      return GameMemory::read_double(ptr());
    }

#ifdef PRIME_DUMP_JSON
    inline nlohmann::json json() {
      return read();
    }
#endif
};

template<class T>
class game_ptr : public game_value<4> {
public:
    game_ptr(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    inline uint32_t read() const {
      return GameMemory::read_u32(ptr());
    }

    T deref() const {
      uint32_t toDeref = ptr();
      uint32_t targetPtr = GameMemory::read_u32(toDeref);
      return T(targetPtr);
    }

#ifdef PRIME_DUMP_JSON
    inline nlohmann::json json() {
      return deref().json();
    }
#endif
};

template<class T>
class game_rc_ptr_data : public game_value<8> {
public:
    game_rc_ptr_data(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    game_ptr<T> raw_ptr = game_ptr<T>(ptr(), 0x0);
    game_u32 refcount = game_u32(ptr(), 0x4);

    inline T deref() {
      return raw_ptr.deref();
    }
};

template<class T>
using game_rc_ptr = game_ptr<game_rc_ptr_data<T>>;

template<class T, uint32_t count>
class game_array : public game_value<T::size * count> {
    static_assert(T::size > 0, "Attempting to create array of an object with undefined size");
public:
    game_array(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value<T::size * count>(base_ptr, ptr_offset) {}

    inline T operator[](std::size_t idx) const {
      assert(idx < count); //In debug mode, error
      return T(this->ptr(), T::size * (idx % count)); //In production, take the modulus and hope for the best
    }

#ifdef PRIME_DUMP_JSON
    inline nlohmann::json json() {
      std::vector<nlohmann::json> res;
      for (size_t i = 0; i < count; i++) {
        T ele = (*this)[i];
        res.push_back(ele.json());
      }
      return res;
    }
#endif
};

#endif //DOLPHIN_EMU_GAME_PTR_H

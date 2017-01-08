//
// Created by pwootage on 1/4/17.
//

#ifndef DOLPHIN_EMU_GAME_PTR_H
#define DOLPHIN_EMU_GAME_PTR_H

#include <cstdint>
#include <cstdio>
#include "GameMemory.h"

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

class game_u32 : public game_value<4> {
public:
    game_u32(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    inline uint32_t read() const {
      return GameMemory::read_u32(ptr());
    }
};

class game_float : public game_value<4> {
public:
    game_float(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    inline float read() const {
      return GameMemory::read_float(ptr());
    }
};


template<class T>
class game_ptr : public game_value<4> {
public:
    game_ptr(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value(base_ptr, ptr_offset) {}

    T deref() const {
      uint32_t toDeref = ptr();
      uint32_t targetPtr = GameMemory::read_u32(toDeref);
      return T(targetPtr);
    }

};

template<class T, uint32_t count>
class game_array : public game_value<T::size * count> {
    static_assert(T::size > 0, "Attempting to create array of an object with undefined size");
public:
    game_array(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value<T::size * count>(base_ptr, ptr_offset) {}

    inline T operator[](std::size_t idx) const {
      assert(idx < count); //In debug mode, error
      game_ptr<T> targetPointer(this->ptr(), T::size * (idx % count)); //In production, take the modulus and hope for the best
      return targetPointer.deref();
    }
};

#endif //DOLPHIN_EMU_GAME_PTR_H

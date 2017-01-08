

#ifndef DOLPHIN_EMU_GAMEMEMORY_H
#define DOLPHIN_EMU_GAMEMEMORY_H

#include <cstdint>

namespace GameMemory {
    std::uint32_t read_u32(std::uint32_t address);
    float read_float(std::uint32_t address);
}

#endif //DOLPHIN_EMU_GAMEMEMORY_H

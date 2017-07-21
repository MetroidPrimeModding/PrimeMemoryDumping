#ifndef PRIME_WATCH_DUMP_RSTL_STRING_HPP
#define PRIME_WATCH_DUMP_RSTL_STRING_HPP

#include "game_value.h"

namespace rstl {
    template <typename T>
    class string : public game_value<16> {
    public:
        explicit string(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value<16>(base_ptr, ptr_offset) {}

        game_ptr<T> data = game_ptr<T>(this->ptr(), 0x0);
        game_u32 unk2 = game_u32(this->ptr(), 0x4);
        game_u32 unk3 = game_u32(this->ptr(), 0x8);
        game_u32 unk4 = game_u32(this->ptr(), 0xC);

        inline std::string read_str() {
          uint32_t maxLen = 512;
          std::string res;
          uint32_t pos = data.read();
          for (uint32_t i = 0; i < maxLen; i++) {
            char c = game_u8(pos, i).read();
            if (c == 0) {
              break;
            }
            res += c;
          }
          return res;
        }
    };
}


#endif //PRIME_WATCH_DUMP_RSTL_STRING_HPP

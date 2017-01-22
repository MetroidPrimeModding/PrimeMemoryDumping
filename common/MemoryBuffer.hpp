#ifndef PRIME_WATCH_DUMP_MEMORYBUFFER_HPP
#define PRIME_WATCH_DUMP_MEMORYBUFFER_HPP

#include <cstdint>
#include <cstring>
#include <string>

class MemoryBuffer {
private:
    uint32_t pos;
    uint32_t len;
    char *buff;
public:
    MemoryBuffer(uint32_t startingSize = 0x100);
    MemoryBuffer(const MemoryBuffer &other) = delete;
    MemoryBuffer& operator=(const MemoryBuffer&) = delete;
    ~MemoryBuffer();

    void resize(uint32_t newSize);

    bool write(const void *data, uint32_t size);

    bool seek(uint32_t pos);

    inline void clear() {
      pos = 0;
    }

    inline char *getBuff() const {
      return buff;
    }

    inline uint32_t size() const {
      return pos;
    }

    inline MemoryBuffer &operator<<(std::string &data) {
      write(data.c_str(), static_cast<uint32_t>(data.size()));
      return *this;
    };

    inline MemoryBuffer &operator<<(const char *data) {
      uint32_t len = static_cast<uint32_t>(strlen(data));
      write(data, len);
      return *this;
    };
};



#endif //PRIME_WATCH_DUMP_MEMORYBUFFER_HPP

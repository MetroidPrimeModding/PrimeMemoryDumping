//
// Created by pwootage on 1/22/17.
//

#include "MemoryBuffer.hpp"

MemoryBuffer::MemoryBuffer(uint32_t startingSize) {
  len = startingSize;
  buff = new char[startingSize];
  pos = 0;
}

MemoryBuffer::~MemoryBuffer() {
  delete buff;
}

void MemoryBuffer::resize(uint32_t newSize) {
  uint32_t oldLen = len;
  const char *oldBuff = buff;

  if (oldLen == newSize) {
    return;
  }

  char *newBuff = new char[newSize];

  if (oldLen < newSize) {
    memcpy(newBuff, oldBuff, oldLen);
  } else {
    memcpy(newBuff, oldBuff, newSize);
  }

  len = newSize;
  buff = newBuff;

  if (pos > len) {
    pos = len;
  }

  delete oldBuff;
}

bool MemoryBuffer::write(const void *data, uint32_t size) {
  if (size + pos >= len) {
    return false;
  }
  memcpy(buff + pos, data, size);
  pos += size;
  return true;
}

bool MemoryBuffer::seek(uint32_t newPos) {
  if (newPos > len) {
    return false;
  }
  pos = newPos;
  return true;
}
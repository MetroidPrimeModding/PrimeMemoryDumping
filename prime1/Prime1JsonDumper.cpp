#include <vector>
#include "Prime1JsonDumper.h"
#include "CGameAllocator.h"

using namespace std;
using namespace nlohmann;

namespace Prime1JsonDumper {
    json parseHeap() {
      json json_heap;
      CGameAllocator allocator(0x804BFD64);

      json_heap["size"] = allocator.heapSize().read();
      vector<json> json_blocks;

      CMemoryBlock block = allocator.first().deref();
      size_t blockid = 0;

      while (block.ptr() != 0 && block.size().read() != 0) {
        json json_block;
        json_block["size"] = block.size().read();
        json_block["start"] = block.ptr();
        json_blocks.push_back(json_block);

        block = block.next().deref();
        blockid++;
      }
      json_heap["blocks"] = json_blocks;
      return json_heap;
    }
};
#ifndef DOLPHIN_EMU_PRIMEJSONDUMPER_H
#define DOLPHIN_EMU_PRIMEJSONDUMPER_H

#ifdef PRIME_DUMP_JSON
#include "json.hpp"

namespace Prime1JsonDumper {
    nlohmann::json parseHeap();
    nlohmann::json parsePlayer();
    nlohmann::json parseCamera();
    nlohmann::json parsePlayerRaw();
    nlohmann::json parseWorld();
    nlohmann::json parsePool();
    nlohmann::json parsePoolBasic();
    nlohmann::json parsePoolSummary();
    nlohmann::json parseHeapStats();
};

#endif

#endif //DOLPHIN_EMU_PRIMEJSONDUMPER_H


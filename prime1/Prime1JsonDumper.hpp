#ifndef DOLPHIN_EMU_PRIMEJSONDUMPER_H
#define DOLPHIN_EMU_PRIMEJSONDUMPER_H

#include "json.hpp"

namespace Prime1JsonDumper {
    nlohmann::json parseHeap();
    nlohmann::json parsePlayer();
    nlohmann::json parsePlayerRaw();
    nlohmann::json parseWorld();
};


#endif //DOLPHIN_EMU_PRIMEJSONDUMPER_H

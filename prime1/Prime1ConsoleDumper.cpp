//
// Created by pwootage on 1/22/17.
//

#include "Prime1ConsoleDumper.hpp"

namespace Prime1ConsoleDumper {

    void dump(MemoryBuffer &res) {
      res << "{";
      {
        res << "\"test\":true";
      }
      res << "}";
    }

}
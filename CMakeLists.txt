add_definitions(-std=c++11 -DJSON_NOEXCEPTION=true)

include_directories(common)
include_directories(.)

set(MEM_SRCS
        prime1/Prime1JsonDumper.cpp
        )

add_library(primememorydumping ${MEM_SRCS})
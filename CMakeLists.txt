add_definitions(-std=c++11 -DJSON_NOEXCEPTION=true)

include_directories(common)

set(MEM_SRCS
        common/game_value.cpp
        prime1/CGameAllocator.cpp
        prime1/Prime1JsonDumper.cpp
        )

add_library(primememorydumping ${MEM_SRCS})
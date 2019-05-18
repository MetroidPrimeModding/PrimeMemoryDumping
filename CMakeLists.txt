add_definitions(-std=c++11 -DJSON_NOEXCEPTION=true)

include_directories(common)
include_directories(.)

set(MEM_SRCS
        prime1/CAABB.hpp
        prime1/CCameraManager.hpp
        prime1/CGameGlobalObjects.hpp
        prime1/CMatrix4f.hpp
        prime1/CPair.hpp
        prime1/CQuaternion.hpp
        prime1/CReservedVector.hpp
        prime1/CStateManager.hpp
        prime1/CVector3f.hpp
        prime1/Prime1ConsoleDumper.hpp
        prime1/SObjectTag.hpp
        prime1/CAABBPrimitive.hpp
        prime1/CFirstPersonCamera.hpp
        prime1/CGameState.hpp
        prime1/CObjectList.hpp
        prime1/CPlayerCameraBob.hpp
        prime1/CRBTree.hpp
        prime1/CSimplePool.hpp
        prime1/CTransform.hpp
        prime1/CWorld.hpp
        prime1/CBallCamera.hpp
        prime1/CGameAllocator.hpp
        prime1/CHealthInfo.hpp
        prime1/CObjectReference.hpp
        prime1/CPlayerState.hpp
        prime1/CRandom16.hpp
        prime1/CSpherePrimitive.hpp
        prime1/Prime1JsonDumper.hpp
        prime1/actors/CActor.hpp
        prime1/actors/CEntity.hpp
        prime1/actors/CGameCamera.hpp
        prime1/actors/CMorphBall.hpp
        prime1/actors/CPhysicsActor.hpp
        prime1/actors/CPlayer.hpp
        prime1/actors/CPlayerGun.hpp
        prime1/rstl/rstl.hpp

        prime1/Prime1JsonDumper.cpp
        prime1/Prime1ConsoleDumper.cpp
        common/MemoryBuffer.cpp
        prime1/CGameArea.hpp)

add_library(primememorydumping ${MEM_SRCS})
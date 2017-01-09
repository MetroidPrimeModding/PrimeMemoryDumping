#include <vector>
#include "prime1/Prime1JsonDumper.hpp"
#include "prime1/CGameAllocator.hpp"
#include "prime1/actors/CPlayer.hpp"
#include "prime1/CWorld.hpp"
#include "prime1/CStateManager.hpp"
#include "prime1/CGameGlobalObjects.hpp"
#include "prime1/CGameState.hpp"

using namespace std;
using namespace nlohmann;

namespace Prime1JsonDumper {
    json parseHeap() {
      json json_heap;
      CGameAllocator allocator(0x804BFD64);

      json_heap["size"] = allocator.heapSize.read();
      vector<json> json_blocks;

      CMemoryBlock block = allocator.first.deref();
      size_t blockid = 0;

      while (block.ptr() != 0 && block.size.read() != 0) {
        json json_block;
        json_block["size"] = block.size.read();
        json_block["start"] = block.ptr();
        json_blocks.push_back(json_block);

        block = block.next.deref();
        blockid++;
      }
      json_heap["blocks"] = json_blocks;
      return json_heap;
    }

    json parsePlayer() {
      json res;
      CStateManager stateManager(CStateManager::LOCATION);
      CPlayer player = stateManager.player.deref();

      res["transform"] = player.transform.matrix.json();
      res["constant_force"] = player.constantForce.json();
      res["angular_momentum"] = player.angularMomentum.json();
      res["velocity"] = player.velocity.json();
      res["angular_velocity"] = player.angularVelocity.json();
      res["momentum"] = player.momentum.json();
      res["force"] = player.force.json();
      res["impulse"] = player.impulse.json();
      res["torque"] = player.torque.json();
      res["angular_impulse"] = player.angularImpulse.json();
      res["collision_primitive"] = player.collisionPrimitive.aabb.values.json();
      res["primitive_offset"] = player.primitiveOffset.json();
      res["translation"] = player.translation.json();
      res["orientation"] = player.orientation.json();
      res["camera_state"] = player.cameraState.read();
      res["morph_state"] = player.morphState.read();
//      json_player["gun"]
      res["morphball"] = player.morphBall.deref().json();

      CPlayerState playerState = stateManager.playerState.deref().deref();
      res["health"] = playerState.healthInfo.health.read();
      res["beam"] = playerState.currentBeam.read();
      res["visor"] = playerState.currentVisor.read();
      res["suit"] =  playerState.currentSuit.read();
      res["inventory"] = playerState.powerups.array.json();

      CGameGlobalObjects global(CGameGlobalObjects::LOCATION);
      CGameState gameState = global.gameState.deref();
      res["timer"] = gameState.playTime.read();

      return res;
    }

    json parsePlayerRaw() {
      json res;
      CStateManager stateManager(CStateManager::LOCATION);
      CPlayer player = stateManager.player.deref();

      res["transform"] = player.transform.rawMatrix.json();
      res["constant_force"] = player.constantForce.rawJson();
      res["angular_momentum"] = player.angularMomentum.rawJson();
      res["velocity"] = player.velocity.rawJson();
      res["angular_velocity"] = player.angularVelocity.rawJson();
      res["momentum"] = player.momentum.rawJson();
      res["force"] = player.force.rawJson();
      res["impulse"] = player.impulse.rawJson();
      res["torque"] = player.torque.rawJson();
      res["angular_impulse"] = player.angularImpulse.rawJson();
      res["collision_primitive"] = player.collisionPrimitive.aabb.rawValues.json();
      res["primitive_offset"] = player.primitiveOffset.rawJson();
      res["translation"] = player.translation.rawJson();
      res["orientation"] = player.orientation.rawJson();
      res["camera_state"] = player.cameraState.read();
      res["morph_state"] = player.morphState.read();
//      json_player["gun"]
      res["morphball"] = player.morphBall.deref().json();

      CPlayerState playerState = stateManager.playerState.deref().deref();
      res["health"] = playerState.healthInfo.health.read();
      res["beam"] = playerState.currentBeam.read();
      res["visor"] = playerState.currentVisor.read();
      res["suit"] =  playerState.currentSuit.read();
      res["inventory"] = playerState.powerups.array.json();

      CGameGlobalObjects global(CGameGlobalObjects::LOCATION);
      CGameState gameState = global.gameState.deref();
      res["timer"] = gameState.playTime.read();

      return res;
    }

    json parseWorld() {
      json res;
      CStateManager stateManager(CStateManager::LOCATION);
      CWorld world = stateManager.world.deref();

      res["phase"] = world.phase.read();
      res["mlvl"] = world.mlvlID.read();
      res["strg"] = world.strgID.read();
      res["area"] = world.currentAreaID.read();

      return res;
    }
};
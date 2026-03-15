#include "ACubicGM.h"
#include "Actors/ACompanionCube.h"
#include "Engine/World.h"
#include "TimerManager.h"

ACubicGM::ACubicGM()
{
  // No connected nodes.
}

ACubicGM::~ACubicGM()
{
  // No connected nodes.
}

void ACubicGM::BeginPlay()
{
  Super::BeginPlay();
  OnCubeSpawned.AddDynamic(this, &ACubicGM::CubeSpawned);
  StartSpawning();
}

void ACubicGM::CubeSpawned(ACompanionCube* SpawnedCube)
{
  OnMaxCubeSpawned.AddDynamic(SpawnedCube, &ACompanionCube::DestroyMe);
  if ((currentNumberOfCubes >= maxSpawnedCubes)) {
    OnMaxCubeSpawned.Broadcast();
    currentNumberOfCubes = 0;
    GetWorld()->GetTimerManager()->ClearTimer(spawnTimerHandle);
  }
}

void ACubicGM::MaxSpawned()
{
  // No event node in graph.
}

void ACubicGM::MaxCubesSpawned()
{
  // No event node in graph.
}

void ACubicGM::StartSpawning()
{
  if ((GetWorld()) != nullptr) {
    GetWorld()->GetTimerManager()->SetTimer(spawnTimerHandle, FTimerDynamicDelegate&(), spawnRate, true, /* In First Delay */);
  }
}

void ACubicGM::SpawnCube()
{
  ACompanionCube* spawnedCube;
  if ((GetWorld()) != nullptr) {
    spawnedCube = GetWorld()->SpawnActor(cubeToSpawn, (FVector(0, 0, 0) + (FVector(1, 0, 0) * currentNumberOfCubes)), FRotator*(), /* Spawn Parameters */);
    if ((spawnedCube) != nullptr) {
      OnCubeSpawned.Broadcast(spawnedCube);
    }
  }
}
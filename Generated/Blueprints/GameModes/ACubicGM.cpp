#include "ACubicGM.h"
#include "../Actors/ACompanionCube.h"
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
  StartSpawning();
}

void ACubicGM::CubeSpawned(ACompanionCube* SpawnedCube)
{
  OnMaxCubeSpawned.AddDynamic(SpawnedCube, &ACompanionCube::DestroyMe);
  currentNumberOfCubes = (currentNumberOfCubes + 1);
  if ((currentNumberOfCubes >= maxSpawnedCubes)) {
    OnMaxCubeSpawned.Broadcast();
    currentNumberOfCubes = 0;
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
    GetWorld()->GetTimerManager().SetTimer(spawnTimerHandle, this, &ACubicGM::SpawnCube, spawnRate, true, 0.f);
  }
}

void ACubicGM::SpawnCube()
{
  ACompanionCube* spawnedCube;
  if ((GetWorld()) != nullptr) {
    spawnedCube = GetWorld()->SpawnActor<ACompanionCube>(cubeToSpawn, FTransform(FQuat::Identity, (FVector(0, 0, 0) + (FVector(100, 0, 0) * currentNumberOfCubes)), FVector(1.0, 1.0, 1.0)), FActorSpawnParameters());
    if ((spawnedCube) != nullptr) {
      CubeSpawned(spawnedCube);
    }
  }
}
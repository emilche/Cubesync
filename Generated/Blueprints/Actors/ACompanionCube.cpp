#include "ACompanionCube.h"

ACompanionCube::ACompanionCube()
{
  PrimaryActorTick.bCanEverTick = true;
  // No connected nodes.
}

ACompanionCube::~ACompanionCube()
{
  // No connected nodes.
}

void ACompanionCube::BeginPlay()
{
  Super::BeginPlay();
  // No connected nodes.
}

void ACompanionCube::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
  // No connected nodes.
}

void ACompanionCube::DestroyMe()
{
}
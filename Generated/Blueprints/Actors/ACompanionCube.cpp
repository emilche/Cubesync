#include "ACompanionCube.h"
#include "Components/StaticMeshComponent.h"

ACompanionCube::ACompanionCube()
{
  PrimaryActorTick.bCanEverTick = true;
  myMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
  SetRootComponent(myMesh);
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
  DestroyActor();
}
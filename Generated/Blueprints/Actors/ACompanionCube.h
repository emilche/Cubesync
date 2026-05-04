#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ACompanionCube.generated.h"

UCLASS()
class CPPTESTPROJECT_API ACompanionCube : public AActor
{
  GENERATED_BODY()

public:
  ACompanionCube();
  virtual ~ACompanionCube();
  virtual void Tick(float DeltaTime) override;
  UFUNCTION()
  void DestroyMe();

protected:
  virtual void BeginPlay() override;
};
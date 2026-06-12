#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Layout/Visibility.h"
#include "AMyCharacter.generated.h"

class ACharacter;

UCLASS()
class CPPTESTPROJECT_API AMyCharacter : public AActor
{
  GENERATED_BODY()

public:
  AMyCharacter();
  virtual ~AMyCharacter();
  virtual void Tick(float DeltaTime) override;

protected:
  virtual void BeginPlay() override;

private:
  UObject* characterMovement;
  float iNTERPSPEED;
  float leanAngle;
  float scaleValue;
  AActor myactor;
  ACharacter newCharacter;
  EVisibility myVisibility;
};
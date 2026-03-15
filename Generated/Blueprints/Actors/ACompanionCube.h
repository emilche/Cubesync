#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ACompanionCube.generated.h"

UCLASS()
class TUTORIAL1_API ACompanionCube : public AActor
{
  GENERATED_BODY()

public:
  ACompanionCube();
  virtual ~ACompanionCube();
  virtual void Tick(float DeltaTime) override;
  void DestroyMe();
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  UStaticMeshComponent* myMesh;

protected:
  virtual void BeginPlay() override;
};
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ACubicGM.generated.h"

class ACompanionCube;

UCLASS()
class CPPTESTPROJECT_API ACubicGM : public AGameModeBase
{
  GENERATED_BODY()

public:
  ACubicGM();
  virtual ~ACubicGM();
  UFUNCTION()
  void CubeSpawned(ACompanionCube* SpawnedCube);
  void MaxSpawned();
  void MaxCubesSpawned();
  UFUNCTION()
  void StartSpawning();
  UFUNCTION()
  void SpawnCube();
  DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCubeSpawned, ACompanionCube*, spawnedCube);
  UPROPERTY(BlueprintAssignable)
  FOnCubeSpawned OnCubeSpawned;
  DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMaxCubeSpawned);
  UPROPERTY(BlueprintAssignable)
  FOnMaxCubeSpawned OnMaxCubeSpawned;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int32 maxSpawnedCubes = 5;
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  TArray<TObjectPtr<AActor>> myCubes;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float spawnRate;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TSubclassOf<AActor> cubeToSpawn;

protected:
  virtual void BeginPlay() override;

private:
  int32 currentNumberOfCubes;
  float currentTime;
  FTimerHandle spawnTimerHandle;
};
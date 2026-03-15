#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ACubicGM.generated.h"

UCLASS()
class TUTORIAL1_API ACubicGM : public AGameModeBase
{
  GENERATED_BODY()

public:
  ACubicGM();
  virtual ~ACubicGM();
  void CubeSpawned(ACompanionCube* SpawnedCube);
  void MaxSpawned();
  void MaxCubesSpawned();
  void StartSpawning();
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
  TSubclassOf<AActor> cubeToSpawn;

protected:
  virtual void BeginPlay() override;

private:
  int32 currentNumberOfCubes;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float spawnRate;
  float currentTime;
  FTimerHandle spawnTimerHandle;
};
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ATest.generated.h"

UCLASS()
class CPPTESTPROJECT_API ATest : public AGameModeBase
{
  GENERATED_BODY()

public:
  ATest();
  virtual ~ATest();

protected:
  virtual void BeginPlay() override;

private:
  UBasePlayer* platypus;
  UBasePlayer* squirrel;
  UMaterial* material;
  int32 number;
  UTextRenderComponent* numberText;
  UStaticMeshComponent* symbol;
};
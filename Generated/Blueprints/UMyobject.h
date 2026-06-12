#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UMyobject.generated.h"

UCLASS()
class CPPTESTPROJECT_API UMyobject : public UObject
{
  GENERATED_BODY()

public:
  UMyobject();
  virtual ~UMyobject();
};
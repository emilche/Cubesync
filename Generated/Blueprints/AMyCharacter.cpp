#include "AMyCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/NavMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

AMyCharacter::AMyCharacter()
{
  PrimaryActorTick.bCanEverTick = true;
  // No connected nodes.
}

AMyCharacter::~AMyCharacter()
{
  // No connected nodes.
}

void AMyCharacter::BeginPlay()
{
  Super::BeginPlay();
  if (((VSize(GetVelocity()) > 0.0) && (!characterMovement->IsFalling()) && (scaleValue != 0.0))) {
    if ((scaleValue > 0.0)) {
      GetPlayerController(/* World Context Object */, 0)->SetControlRotation(MakeRotator(leanAngle, /* Pitch */, /* Yaw */).RInterpTo(GetControlRotation(), GetWorldDeltaSeconds(/* World Context Object */), iNTERPSPEED));
    } else {
      if ((scaleValue < 0.0)) {
        GetPlayerController(/* World Context Object */, 0)->SetControlRotation(MakeRotator((350.000000 - leanAngle), /* Pitch */, /* Yaw */).RInterpTo(GetControlRotation(), GetWorldDeltaSeconds(/* World Context Object */), iNTERPSPEED));
      }
    }
  } else {
    GetPlayerController(/* World Context Object */, 0)->SetControlRotation(MakeRotator(/* Roll */, /* Pitch */, /* Yaw */).RInterpTo(GetControlRotation(), GetWorldDeltaSeconds(/* World Context Object */), iNTERPSPEED));
  }
}

void AMyCharacter::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
  // No connected nodes.
}
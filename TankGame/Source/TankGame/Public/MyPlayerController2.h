// Autor: Jac3k

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController2.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API AMyPlayerController2 : public APlayerController
{
	GENERATED_BODY()

public:
	// it searches for function virtual method BeginPlay() at the parent classes, change and extend
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& outHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const; // not changing any member variables

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333333;

	UPROPERTY()
	ATank* PossesedTank = nullptr;
};

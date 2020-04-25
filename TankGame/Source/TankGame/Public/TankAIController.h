// Autor: Jac3k

#pragma once

#include "Engine/World.h"
#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

	// it searches for function virtual method BeginPlay() at the parent classes and change it in this class
	void BeginPlay() override;
	
	UPROPERTY()
	ATank* PossesedTank = nullptr;

	UPROPERTY()
	ATank* FoundPlayersTank = nullptr;
};

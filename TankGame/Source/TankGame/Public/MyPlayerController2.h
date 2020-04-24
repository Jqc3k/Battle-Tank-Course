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
	ATank* GetControlledTank() const;
	void BeginPlay() override; // it searches for function virtual method BeginPlay() at the parent classes, change and extend
	
	UPROPERTY()
	ATank* PossesedTank = nullptr;
};

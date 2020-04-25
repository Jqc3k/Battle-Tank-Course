// Autor: Jac3k


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay(); // it makes sure the BeginPlay is called

    FoundPlayersTank = GetPlayerTank();
    PossesedTank = GetControlledTank();
    // protecting from access to null pointers and log the result
    if (PossesedTank && FoundPlayersTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AI possesed a tank %s, and found players tank %s"),
        *PossesedTank->GetName(), *FoundPlayersTank->GetName());
    }

    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Not possesed a tank or cant find players tank"));
    }
}

// return a pawn that a player is currently possesing (AI possessing)
ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn()); 
}

ATank* ATankAIController::GetPlayerTank() const
{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
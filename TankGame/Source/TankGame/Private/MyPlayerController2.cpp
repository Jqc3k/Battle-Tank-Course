// Autor: Jac3k

#include "MyPlayerController2.h"


void AMyPlayerController2::BeginPlay()
{
    Super::BeginPlay(); // it makes sure the BeginPlay is called
    UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play"));

    PossesedTank = GetControlledTank();
    if (PossesedTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Possesed a tank %s."), *PossesedTank->GetName());
    }

    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Not possesed a tank."));
    }
    

}



// return a pawn that a player is currently possesing
ATank* AMyPlayerController2::GetControlledTank() const
{
    return Cast<ATank>(GetPawn()); 
}


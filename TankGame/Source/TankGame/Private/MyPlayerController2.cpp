// Autor: Jac3k

#include "MyPlayerController2.h"

void AMyPlayerController2::BeginPlay()
{
    Super::BeginPlay(); // it makes sure the BeginPlay is called

    PossesedTank = GetControlledTank();
    if (PossesedTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player possesed a tank %s."), *PossesedTank->GetName());
    }

    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Not possesed a tank."));
    }
}

// Called every frame
void AMyPlayerController2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    // UE_LOG(LogTemp, Warning, TEXT("Tick"));

    // start the tank moving barrel
    AimTowardsCrosshair();
}

// return a pawn that a player is currently possesing
ATank* AMyPlayerController2::GetControlledTank() const
{
    return Cast<ATank>(GetPawn()); 
}

void AMyPlayerController2::AimTowardsCrosshair()
{
    // nullpointer protection
    if (!GetControlledTank()) {return;}
    FVector HitLocation; // out parameter

    if (GetSightRayHitLocation(HitLocation))
    {
        // UE_LOG(LogTemp, Warning, TEXT("Look direciton: %s"), *HitLocation.ToString())

    }
}

bool AMyPlayerController2::GetSightRayHitLocation(FVector& outHitLocation) const
{
    int32 ViewportSizeX, VeiwportSizeY;
    GetViewportSize(ViewportSizeX, VeiwportSizeY);
    FVector WorldDirection;

    FVector2D ScreenLocationDot;
    ScreenLocationDot.X = ViewportSizeX * CrossHairXLocation;
    ScreenLocationDot.Y = VeiwportSizeY * CrossHairYLocation;

    if (GetLookDirection(ScreenLocationDot, WorldDirection))
    {
        UE_LOG(LogTemp, Warning, TEXT("World direction: %s"), *WorldDirection.ToString());
    }

    return true;
}

bool AMyPlayerController2::GetLookDirection(FVector2D ScreenLocationDot, FVector& LookDirection) const
{
    FVector WorldLocation; // To be discarded
    // world direciton - camera coordinates - position of the excact point in the camera wiev
    return DeprojectScreenPositionToWorld(ScreenLocationDot.X, ScreenLocationDot.Y, WorldLocation, LookDirection);
}
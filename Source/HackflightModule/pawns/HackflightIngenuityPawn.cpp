/*
* Class implementation for Ingenuity pawn in MulticopterSim
*
* Copyright (C) 2021 Simon D. Levy
*
* MIT License
*/

#include "HackflightIngenuityPawn.h"


AHackflightIngenuityPawn::AHackflightIngenuityPawn()
{
    _ingenuity.build(this);
}

void AHackflightIngenuityPawn::PostInitializeComponents()
{
    _ingenuity.PostInitializeComponents();

    Super::PostInitializeComponents();
}

// Called when the game starts or when spawned
void AHackflightIngenuityPawn::BeginPlay()
{
    _flightManager = new FHackflightFlightManager(this, &_mixer, &_motors, &_ingenuity.dynamics);

    _ingenuity.BeginPlay(_flightManager);

    Super::BeginPlay();
}

void AHackflightIngenuityPawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    _ingenuity.EndPlay();

    Super::EndPlay(EndPlayReason);
}

// Called automatically on main thread
void AHackflightIngenuityPawn::Tick(float DeltaSeconds)
{
    _ingenuity.Tick(DeltaSeconds);

    _flightManager->tick();

    Super::Tick(DeltaSeconds);
}



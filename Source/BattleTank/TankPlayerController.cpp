// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// check posession status of tank
	auto PossesedTank = GetControlledTank();
	if (!PossesedTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Did you hire an exorcist for a programmer? Because I'm not possessing anything."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled Tank: %s"), *(PossesedTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


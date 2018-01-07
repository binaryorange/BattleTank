// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	// check status of tank
	auto PlayerTank = GetPlayerController();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI failed to find player tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found player tank: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return  Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerController() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;  }

	return Cast<ATank>(PlayerPawn);
}



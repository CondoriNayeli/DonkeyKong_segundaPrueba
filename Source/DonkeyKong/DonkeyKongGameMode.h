// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DonkeyKongGameMode.generated.h"
class AComponentPlataforma;
class AObstaculo;
class ACubosDisparo;
UCLASS(minimalapi)
class ADonkeyKongGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADonkeyKongGameMode();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	TArray < AComponentPlataforma* > componentesPlataforma;
	// TMap para almacenar los obstáculos en plataformas
	TMap<int32, AObstaculo*> Obstaculos;
	//TArray<AActor*> ContCubos;
	TArray<ACubosDisparo*> CubosDisparoArray;

private:
	TSet<AComponentPlataforma*> PlataformasConCubos;
	//class ACubosDisparo* Cd;

	FTimerHandle TimerHandle_GenerarCubosDisparo;
	void GenerarCuboDisparo();
//
//private:
//	FTimerHandle TimerHandle_DestruirCuboDisparo;
//	void DestruirCuboDisparo(ACubosDisparo* CuboDisparo, AComponentPlataforma* Plataforma);
};






// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubosDisparo.generated.h"

UCLASS()
class DONKEYKONG_API ACubosDisparo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubosDisparo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class UStaticMeshComponent* CuboMesh;

    // Para que dispare a la derecha
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Fire;

    // Tasa de disparo
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Disparo")
    float FireRate;

    // Bandera para controlar si puede disparar
    uint32 bCanFire : 1;

    // Función para disparar
    void FireShot();

    // Temporizador para manejar el intervalo entre disparos
    FTimerHandle TimerHandle_ShotTimerExpired;
    void ShotTimer();

    // Ubicación fija para el cubo de disparo
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ubicación")
    FVector FixedLocation;

};

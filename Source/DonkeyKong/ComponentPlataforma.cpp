// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentPlataforma.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
AComponentPlataforma::AComponentPlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	meshPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	meshPlataforma->SetStaticMesh(MeshAsset.Object);
	RootComponent = meshPlataforma;

	FVector NewScale(2.0f,6.0f,0.5f); 
	SetActorScale3D(NewScale);
	// Inicializar variables
	velocidadMovimiento = 200.0f;
	moverPlataformaMedio = false;
	moviendoHaciaObjetivo = true;

}

// Called when the game starts or when spawned
void AComponentPlataforma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AComponentPlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (moverPlataformaMedio) 
	{
		FVector posicionActual = GetActorLocation();
		FVector nuevaPosicion;

		if (moviendoHaciaObjetivo)
		{
			nuevaPosicion = FMath::VInterpConstantTo(posicionActual, posicionObjetivo,DeltaTime, velocidadMovimiento);
			if (nuevaPosicion.Equals(posicionObjetivo, 1.0f)) 
			{
				moviendoHaciaObjetivo = false;
			}
		}
		else {
			nuevaPosicion = FMath::VInterpConstantTo(posicionActual, posicionInicial, DeltaTime, velocidadMovimiento);
			if (nuevaPosicion.Equals(posicionInicial, 1.0f)) {
				moviendoHaciaObjetivo = true;
			}
		}

		SetActorLocation(nuevaPosicion);
	}
}

void AComponentPlataforma::IniciarMovimiento(FVector nuevaPosicionObjetivo)
{
	posicionInicial = GetActorLocation();
	posicionObjetivo = nuevaPosicionObjetivo;
	moverPlataformaMedio = true;
	moviendoHaciaObjetivo = true;
}



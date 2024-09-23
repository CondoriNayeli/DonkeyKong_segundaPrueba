// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstaculo.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
AObstaculo::AObstaculo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Cargar la malla del obstáculo
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/Obstaculo/StaticMeshObstaculo.StaticMeshObstaculo'"));//("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	MeshObstaculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObstaculoMesh"));
	MeshObstaculo->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.25f));//0.2
	MeshObstaculo->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	MeshObstaculo->SetStaticMesh(MeshAsset.Object);
	RootComponent = MeshObstaculo;

	// Inicializar variables de movimiento
	VelocidadMovimiento = 200.0f;
	MoviendoHaciaArriba = true;

}

// Called when the game starts or when spawned
void AObstaculo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Movimiento del obstáculo
	FVector PosicionActual = GetActorLocation();
	FVector NuevaPosicion;

	if (MoviendoHaciaArriba)
	{
		NuevaPosicion = FMath::VInterpConstantTo(PosicionActual, PosicionObjetivo, DeltaTime, VelocidadMovimiento);
		if (NuevaPosicion.Equals(PosicionObjetivo, 1.0f))
		{
			MoviendoHaciaArriba = false;
		}
	}
	else
	{
		NuevaPosicion = FMath::VInterpConstantTo(PosicionActual, PosicionInicial, DeltaTime, VelocidadMovimiento);
		if (NuevaPosicion.Equals(PosicionInicial, 1.0f))
		{
			MoviendoHaciaArriba = true;
		}
	}

	SetActorLocation(NuevaPosicion);
}

void AObstaculo::IniciarMovimiento(FVector NuevaPosicionObjetivo, float Velocidad)
{
	PosicionInicial = GetActorLocation();
	PosicionObjetivo = NuevaPosicionObjetivo;
	VelocidadMovimiento = Velocidad;
	MoviendoHaciaArriba = true;
}


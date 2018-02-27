// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyController.h"


// Sets default values
AEnemyController::AEnemyController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create the Box Collider
	EnemyRootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PlayerBoxCollider"));
	EnemyRootBox->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	EnemyRootBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	EnemyRootBox->SetCollisionProfileName(TEXT("BlockAll"));
	EnemyRootBox->SetSimulatePhysics(false);
	EnemyRootBox->SetEnableGravity(false);

	RootComponent = EnemyRootBox;

	//Create our mesh
	EnemyMeshBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerCube"));
	EnemyMeshBox->SetupAttachment(RootComponent);

	this->Speed = 0.5f;
	this->Movement = FVector(1.0f, 1.0f, 0.0f);
}

// Called when the game starts or when spawned
void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move the object
	FVector MyLocation = GetActorLocation();
	FVector PlayerLocation = Player->GetActorLocation();
	MyLocation += (PlayerLocation-MyLocation) * DeltaTime * Speed;
	SetActorLocation(MyLocation);

	// Rotate to face the player
	FRotator FacePlayer = FRotationMatrix::MakeFromX(PlayerLocation - MyLocation).Rotator();
	SetActorRotation(FacePlayer);
}


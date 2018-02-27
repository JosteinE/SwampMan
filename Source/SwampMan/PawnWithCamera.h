// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/StaticMesh.h"
#include "PawnWithCamera.generated.h"

UCLASS()
class SWAMPMAN_API APawnWithCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnWithCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* OurCameraSpringArm;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* OurCamera;

	UPROPERTY(VisibleAnywhere)
	class UShapeComponent* RootBox;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* PlayerBox;

	UPROPERTY(EditAnywhere)
	float MovementSpeed = 500.0f;

	UPROPERTY(EditAnywhere)
	float SprintSpeed = 850.0f;

	UPROPERTY(EditAnywhere)
	float ZoomedInCameraDistance = 300.0f;

	UPROPERTY(EditAnywhere)
	float ZoomedOutCameraDistance = 800.0f;

	UPROPERTY(EditAnywhere)
	float FOVZoomedIn = 90.0f;

	UPROPERTY(EditAnywhere)
	float FOVZoomedOut = 90.0f;

	//Input variables
	APlayerController* PcMouse;
	FVector2D MovementInput;
	FVector2D MouseLoc;
	float ZoomFactor;
	bool bZoomingIn;
	bool bFireProjectile;
	bool bSprinting;

	//Input functions
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void MouseY(float AxisValue);
	void MouseX(float AxisValue);
	void ZoomIn();
	void ZoomOut();
	void ShootingProjectile();
	void NotShootingProjectile();
	void IsSprinting();
	void IsNotSprinting();
};
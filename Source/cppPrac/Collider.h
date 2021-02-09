// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ColliderMovementComponent.h"
#include "Collider.generated.h"

UCLASS()
class CPPPRAC_API ACollider : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* MeshComponent;
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USphereComponent* SphereComponent;
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Movement");
	class UColliderMovementComponent* OurMovementComponent;

	virtual UPawnMovementComponent* GetMovementComponent() const override;

	FORCEINLINE UStaticMeshComponent* getMeshComponent() { return MeshComponent; }
	FORCEINLINE void setMeshComponent(UStaticMeshComponent* Mesh) { MeshComponent = Mesh; }
	FORCEINLINE USphereComponent* getSphereComponent() { return SphereComponent; }
	FORCEINLINE void setSphereComponent(USphereComponent* Sphere) { SphereComponent = Sphere; }

	FORCEINLINE UCameraComponent* getcameraComponent() { return Camera; }
	FORCEINLINE void setCameraComponent(UCameraComponent* InCamera) { Camera = InCamera; }
	FORCEINLINE USpringArmComponent* getSpringArmComponent() { return SpringArm; }
	FORCEINLINE void setSpringArmComponent(USpringArmComponent* InSpringArm) { SpringArm = InSpringArm; }

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void PitchCamera(float AxisValue);
	void YawCamera(float AxisValue);

	FVector2D CameraInput;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "MainCharacter.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
		if (Pawn)
		{
			Main = Cast<AMainCharacter>(Pawn);
		}
	}
}

void UMainAnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}

	if (Pawn)
	{
		FVector Velocity = Pawn->GetVelocity();
		FVector LateralVelocity = FVector(Velocity.X, Velocity.Y, 0.f);
		MovementSpeed = LateralVelocity.Size();

		bIsInAir = Pawn->GetMovementComponent()->IsFalling();
		if (Main == nullptr)
		{
			Main = Cast<AMainCharacter>(Pawn);
		}
	}
}
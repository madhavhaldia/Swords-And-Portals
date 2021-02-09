// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "FloorSwitch.generated.h"

UCLASS()
class CPPPRAC_API AFloorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSwitch();
	/**
	*Trigger Overlap volume for functionality to be triggered
	*/
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = FloorSwitch)
	UBoxComponent* TriggerBox;
	/*Switch for the character to step on*/
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = FloorSwitch)
	UStaticMeshComponent* FloorSwitch;
	/**Door to move when the floor switch is pressed*/
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = FloorSwitch)
	UStaticMeshComponent* Door;

	UPROPERTY(BlueprintReadWrite, Category = FloorSwitch)
	FVector InitialDoorLocation;

	UPROPERTY(BlueprintReadWrite, Category = FloorSwitch)
	FVector InitialSwitchLocation;


	FTimerHandle SwitchHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FloorSwitch);
	float SwitchTime;
	bool bCharacterOnSwitch;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
	void OnOverlapEnd( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch)
	void RaiseDoor();
	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch)
	void LowerDoor();
	

	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch)
	void RaiseFloorSwitch();
	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch)
	void LowerFloorSwitch();

	UFUNCTION(BlueprintCallable, Category = FloorSwitch)
	void UpdateDoorLocation(float Z);
	UFUNCTION(BlueprintCallable, Category = FloorSwitch)
	void UpdateFloorSwitchLocation(float Z);
	UFUNCTION()
	void CloseDoor();

};

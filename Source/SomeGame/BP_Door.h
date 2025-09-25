// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_Door.generated.h"

UCLASS()
class SOMEGAME_API ABP_Door : public AActor
{
	GENERATED_BODY()
	
public:

	// define a variable of type UStaticMesh... and using the macro UPROPERTY we can assign properties and functionality
	// (in this case, we made it visible from any details panel of unreal, allow it to be used from blueprint and assign a category)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	bool ShouldOpenDoor;

	float YawIncrement;
	
	// Sets default values for this actor's properties
	ABP_Door();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// this variables indicates the locks that the door has, in this case it will be 4, so it will need 4 buttons in order to be opened
	float LocksUnlocked = 0;
	float LocksNeeded = 4;
	bool Opened = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Actions")
		void OpenDoor();
	
	UFUNCTION(BlueprintCallable, Category = "Actions")
		void CloseDoor();
	
};

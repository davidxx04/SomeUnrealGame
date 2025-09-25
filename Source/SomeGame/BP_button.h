// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "BP_Door.h"
#include "GameFramework/Actor.h"
#include "BP_button.generated.h"  //this has to be the last include

UCLASS()
class SOMEGAME_API ABP_button : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABP_button();

protected:
	bool bTriggered = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* ButtonMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USphereComponent* SphereCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterialInterface* ButtonMaterialDefault;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterialInterface* ButtonMaterialPressed;

	// THE NEXT TWO FUNCTIONS WILL BE CHANGED WHEN THE INTERACTION COMPONENT BE CREATED
	UFUNCTION()
		void OnButtonPressed(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// this will be deleted because the button will be done by pushing it at it interactions ends there
	// UFUNCTION()
	// 	void OnButtonReleased(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	//
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Config")
	ABP_Door* DoorRef;
};

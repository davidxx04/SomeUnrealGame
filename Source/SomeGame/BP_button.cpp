// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_button.h"
#include "PlayerCppParent.h"
#include "Components/SphereComponent.h"

// Sets default values
ABP_button::ABP_button()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMesh"));
	ButtonMesh -> SetupAttachment(RootComponent);

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision -> SetupAttachment(ButtonMesh);
	SphereCollision -> SetSphereRadius(100.0f);

	// this is the binding, with this syntax when and actor begin overlapping the next function is called
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ABP_button::OnButtonPressed);
	// SphereCollision->OnComponentEndOverlap.AddDynamic(this, &ABP_button::OnButtonReleased);
}

// Called when the game starts or when spawned
void ABP_button::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABP_button::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABP_button::OnButtonPressed(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Se activa OnButtonPressed"));
	// I have created a PlayerCppParent which is a class of the same type as the blueprint one that I have, but as the other one is a blueprint made class, I cannot call it from c++ code si I had to create another character class to parent it with the original
	if (!bTriggered)
	{
		if (OtherActor->IsA(APlayerCppParent::StaticClass()) && DoorRef)
		{
			DoorRef->OpenDoor();
			ButtonMesh->SetMaterial(0, ButtonMaterialPressed);
			bTriggered = true;
		}
	}
}

// void ABP_button::OnButtonReleased(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
// {
// 	if (OtherActor->IsA(APlayerCppParent::StaticClass()) && DoorRef)
// 	{
// 		DoorRef->CloseDoor();
// 		ButtonMesh->SetMaterial(0, ButtonMaterialDefault);
// 	}
//}


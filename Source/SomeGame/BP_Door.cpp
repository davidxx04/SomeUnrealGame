// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Door.h"

#include "IAssetTypeActions.h"

// Sets default values
ABP_Door::ABP_Door()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// here I assign a default value for my variable door (which firstly is only text), then I attach it to the RootComponent (remember the blueprint hierarchy stuff)
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABP_Door::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_Door::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//the system is made this way, with the newRotation just in case I want to close the door eventually, to make it flexible
	if (ShouldOpenDoor)
	{
		FTransform currentTransform;
		currentTransform = DoorMesh->GetRelativeTransform();
		FVector currentLocation = currentTransform.GetLocation();
		// Subir en Z (50 unidades)
		FVector newLocation = currentLocation + FVector(0.f, 0.f, 10.f);
		currentTransform.SetLocation(newLocation);
		DoorMesh->SetRelativeTransform(currentTransform);
		// when the animation finishes
		if (currentLocation.Z > 300.f)
		{
			Opened = true;
		}

		// stop when it is high enough
		if (Opened)
		{
			ShouldOpenDoor = false;
		}
		
	}

}


void ABP_Door::OpenDoor()
{
	// if (GetActorRotation().Yaw < 90)
	// {
		YawIncrement = 2.0f;
		//here ir unlocks one more lock (a button for example) and checks if all the locks have been unlocked in order to open the door
		LocksUnlocked += 1;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("LocksUnlocked: %f"), LocksUnlocked));
		if (LocksUnlocked >= LocksNeeded)
		{
		ShouldOpenDoor = true;
		}
	// }
}

// it will never be called in principle but is good to have it created just in case i want to close the door, that is way the system is made this way
void ABP_Door::CloseDoor()
{
	if (GetActorRotation().Yaw > 0)
	{
		YawIncrement = -2.0f;
		ShouldOpenDoor = true;
	}
}

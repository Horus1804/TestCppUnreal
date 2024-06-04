// Fill out your copyright notice in the Description page of Project Settings.


#include "Moving_Platform.h"


// Sets default values
AMoving_Platform::AMoving_Platform()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MovingPlatformMesh"));
	SetRootComponent(Mesh);
	Mesh->SetMobility(EComponentMobility::Movable);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetEnableGravity(false);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	Mesh->SetGenerateOverlapEvents(true);
	Mesh->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"))); 
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMoving_Platform::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMoving_Platform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Blueprint Native Event override implementation
void AMoving_Platform::MovePlatform_Implementation()
{
	if(CanMove == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("CanMovePlatform"));
		UE_LOG(LogTemp,Warning,TEXT("CanMovePlatform"));
	}
}
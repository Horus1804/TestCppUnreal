// Fill out your copyright notice in the Description page of Project Settings.


#include "Trigger_Box.h"
#include "Components/BoxComponent.h"
#include "TestCppUnreal/TestCppUnrealCharacter.h"

// Sets default values
ATrigger_Box::ATrigger_Box()
{
	Box =CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetBoxExtent(FVector(200,200,200));
	Box->SetCollisionProfileName(TEXT("Trigger"));
	Box->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Box->OnComponentBeginOverlap.AddDynamic(this, &ATrigger_Box::OnBoxBeginOverlap);
	RootComponent = Box;

	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATrigger_Box::BeginPlay()
{
	Super::BeginPlay();
	Box->SetVisibility(true);
	Box->SetHiddenInGame(false);
	
}

// Called every frame
void ATrigger_Box::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATrigger_Box::ReactToTrigger_Implementation()
{
	UE_LOG(LogTemp,Warning,TEXT("Interface_COUCOU"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Interface_COUCOU"));
	return false;
}

void ATrigger_Box::TestInterfaceCall_Implementation()
{
	IReactToTriggerInterface::TestInterfaceCall_Implementation();
	UE_LOG(LogTemp,Warning,TEXT("TESTINTERFACECALL"));
}

void ATrigger_Box::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                     UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// cast to player character if true
	if(ATestCppUnrealCharacter* PlayerRef = Cast<ATestCppUnrealCharacter>(OtherActor))
	{
		UE_LOG(LogTemp,Warning,TEXT("Overlapp"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap"));
	}
}

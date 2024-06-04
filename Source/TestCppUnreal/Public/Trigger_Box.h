// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReactToTriggerInterface.h"
#include "Trigger_Box.generated.h"

class UBoxComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCanMovePlatform, bool, canmove);

UCLASS(BlueprintType, Category="MyGame")
class TESTCPPUNREAL_API ATrigger_Box : public AActor, public IReactToTriggerInterface
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Box")
	UBoxComponent* Box;
	
public:	
	// Sets default values for this actor's properties
	ATrigger_Box();

	UPROPERTY(BlueprintAssignable,Blueprintable)
	FCanMovePlatform CanMovePlatform;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual bool ReactToTrigger_Implementation() override;
	virtual void TestInterfaceCall_Implementation() override;
	
	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TestDelegateActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTestDelegateComp);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTCPPUNREAL_API UTestDelegateActor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTestDelegateActor();

	UPROPERTY(Blueprintable,BlueprintAssignable)
	FTestDelegateComp TestDelegateComp;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

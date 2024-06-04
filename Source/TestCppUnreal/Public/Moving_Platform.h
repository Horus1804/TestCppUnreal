// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Moving_Platform.generated.h"

UCLASS(BlueprintType, Category="MyGame")
class TESTCPPUNREAL_API AMoving_Platform : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Mesh")
	UStaticMeshComponent* Mesh;
	
public:	
	// Sets default values for this actor's properties
	AMoving_Platform();
	bool CanMove = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="MyGame")
	void MovePlatform();


};

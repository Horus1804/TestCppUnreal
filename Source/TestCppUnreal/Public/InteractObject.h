#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReactToTriggerInterface.h"
#include "InteractObject.generated.h"



UCLASS(BlueprintType, Category="MyGame")
class AInteractObject : public AActor, public IReactToTriggerInterface
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Mesh")
	UStaticMeshComponent* Mesh;

public:
	AInteractObject();
	
	
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	
	// Blueprint Native Event override
	virtual bool ReactToTrigger_Implementation() override;
	virtual void TestInterfaceCall_Implementation() override;

	UFUNCTION()
	void TestCallDelegate(bool isGrabbed);
};
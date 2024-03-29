#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSpawnActor.generated.h"

UCLASS()
class UNREALPROJ_API ACSpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACSpawnActor();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

private:
	UFUNCTION()
		void ChangeColor();

private:
	class UMaterialInstanceDynamic* Material; 
};

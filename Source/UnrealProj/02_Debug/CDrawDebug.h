#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CDrawDebug.generated.h"

UCLASS()
class UNREALPROJ_API ACDrawDebug : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FVector		InitLocation[5];
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FBox		Box;
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FTransform	Transform;

private :
	FVector Location[5];

public:	
	ACDrawDebug();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CActorOverlap.generated.h"

UCLASS()
class UNREALPROJ_API ACActorOverlap : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene; // << Root¸¦ ¸ÃÀ½

	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;


private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:	
	ACActorOverlap();

protected:
	virtual void BeginPlay() override;


};

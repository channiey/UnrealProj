#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSpawner.generated.h"

UCLASS()
class UNREALPROJ_API ACSpawner : public AActor
{
	GENERATED_BODY()
	
private :
	// Before
	// UClass* spawnClass
	
	// << : After - 블루프린트 상에서 클래스 확장시, 불필요한 클래스 안보이게해줌
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class ACSpawnActor> spawnClass[3];

	class ACSpawnActor* spawnActors[3];
	
public:	
	ACSpawner();

protected:
	virtual void BeginPlay() override;


};

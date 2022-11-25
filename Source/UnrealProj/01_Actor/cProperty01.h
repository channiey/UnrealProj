#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "cProperty01.generated.h"

UCLASS()
class UNREALPROJ_API AcProperty01 : public AActor
{
	GENERATED_BODY()
	
public:	
	AcProperty01();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		int A = 10;
	UPROPERTY(EditInstanceOnly)
		int B = 20;
	UPROPERTY(EditDefaultsOnly)
		int C;
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int D = 40;
};

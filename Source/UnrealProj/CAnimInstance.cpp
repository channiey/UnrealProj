#include "CAnimInstance.h"
#include "Global.h" // << :
#include "GameFramework/Character.h" // << :

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay(); // Super == Base (부모 클래스)

	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	CheckNull(OwnerCharacter);

	Speed = OwnerCharacter->GetVelocity().Size2D();

}
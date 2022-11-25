#include "CPlayer.h"
#include "Global.h" // << :
#include "GameFramework/SpringArmComponent.h"			// << :
#include "GameFramework/CharacterMovementComponent.h"	// << :
#include "Camera/CameraComponent.h"						// << :
#include "Components/CapsuleComponent.h"				// << :

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	// << : Set the Camera
	CHelpers::CreateComponent<USpringArmComponent>(this, &SpringArm, "SpringArm", GetCapsuleComponent());
	CHelpers::CreateComponent<UCameraComponent>(this, &Camera, "Camera", SpringArm);

	// << : Set the Movement
	bUseControllerRotationYaw = false; // << : Block Rotation Y Axis
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;

	// << : Set the Mesh
	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Character/Mesh/SK_Mannequin.SK_Mannequin'");
	GetMesh()->SetSkeletalMesh(mesh);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	// << : Set the Camera
	SpringArm->SetRelativeLocation(FVector(0, 0, 60));
	SpringArm->TargetArmLength = 200.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;

	
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


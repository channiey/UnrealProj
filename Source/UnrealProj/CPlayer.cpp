#include "CPlayer.h"
#include "Global.h"										// << :
#include "CAnimInstance.h"								// << :
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

	// << : Set the Animation
	TSubclassOf<UAnimInstance> animInstance;
	CHelpers::GetClass<UAnimInstance>(&animInstance, "AnimBlueprint'/Game/ABP_CPlayer.ABP_CPlayer_C'");
	GetMesh()->SetAnimInstanceClass(animInstance);

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

// << : 입력값에 대한 세팅 경로 에디터 
// << : (편집 -> 프로젝트 세팅 -> 입력 -> 바인딩), 저장된 입력 세팅(프로젝트 파일 내에서 임포트, DefaultInputSetting.ini)

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// << : 축 매핑 키세팅을 함수와 연결
	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::OnMoveRight);
	PlayerInputComponent->BindAxis("HorizontalLook", this, &ACPlayer::OnHorizontalLook);
	PlayerInputComponent->BindAxis("VerticalLook", this, &ACPlayer::OnVerticalLook);

	// << : 액션 매핑 키세팅을 함수와 연결	
	PlayerInputComponent->BindAction("Running", EInputEvent::IE_Pressed, this, &ACPlayer::OnRunning);
	PlayerInputComponent->BindAction("Running", EInputEvent::IE_Released, this, &ACPlayer::OffRunning);
}


void ACPlayer::OnMoveForward(float Axis)
{
	// << 현재 Yaw 회전 값을 갖고 온다
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);

	// << : 방향 벡터를 구한다
	FVector direction = FQuat(rotator).GetForwardVector().GetSafeNormal2D();

	AddMovementInput(direction, Axis);
}

void ACPlayer::OnMoveRight(float Axis)
{
	// << 현재 Yaw 회전 값을 갖고 온다
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);

	// << : 방향 벡터를 구한다
	FVector direction = FQuat(rotator).GetRightVector().GetSafeNormal2D();

	AddMovementInput(direction, Axis);
}

void ACPlayer::OnHorizontalLook(float Axis)
{
	AddControllerYawInput(Axis);
}

void ACPlayer::OnVerticalLook(float Axis)
{
	AddControllerPitchInput(Axis);
}

void ACPlayer::OnRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}

void ACPlayer::OffRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
}


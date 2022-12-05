#include "CLogActor.h"
#include "Global.h"

ACLogActor::ACLogActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACLogActor::BeginPlay()
{
	Super::BeginPlay();

	CLog::Print(10);
	CLog::Print(20, 1);
	CLog::Print(30, 2, 20.0f);
	CLog::Print(40, 2, 20.0f);

	CLog::Print("Unreal Proj");
	CLog::Print(GetActorLocation());
	CLog::Print(GetActorRotation());

	CLog::Log(31);
	CLog::Log(PI);
	CLog::Log("Unreal Proj");
	CLog::Log(GetActorLocation());
	CLog::Log(GetActorRotation());

	CLog::Log(this);
	PriltLine();
}

void ACLogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Time += DeltaTime;
	CLog::Print(Time, 4);

}


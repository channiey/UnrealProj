#include "UnrealProjGameModeBase.h"
#include "Global.h" // << :

AUnrealProjGameModeBase::AUnrealProjGameModeBase()
{
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/BP_CPlayer.BP_CPlayer_C'");
	// 블루프린트일 경우에는, 경로명 마지막에 꼭! "_C"를 붙어주어야 한다.
}

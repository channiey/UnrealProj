#include "UnrealProjGameModeBase.h"
#include "Global.h" // << :

AUnrealProjGameModeBase::AUnrealProjGameModeBase()
{
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/BP_CPlayer.BP_CPlayer_C'");
	// �������Ʈ�� ��쿡��, ��θ� �������� ��! "_C"�� �پ��־�� �Ѵ�.
}

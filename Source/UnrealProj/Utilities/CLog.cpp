#include "CLog.h"
#include "Engine.h"

DEFINE_LOG_CATEGORY_STATIC(GameObject, Warning, All); // >> : Log(로그창) 커스텀 카테고리

void CLog::Print(int32 InValue, int32 InKey, float Duration, FColor InColor)
{
	// << : 엔진 파일을 이용해 스크린에 메시지를 출력한다.
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, FString::FromInt(InValue));
}

void CLog::Print(float InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, FString::SanitizeFloat(InValue));
}

void CLog::Print(const FString& InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue);
}


void CLog::Print(const FVector& InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue.ToString());
}


void CLog::Print(const FRotator& InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue.ToString());
}

void CLog::Log(int32 InValue)
{
	//UE_LOG(LogTemp, Display, L"%d", InValue);

	// >> : Log(로그창) 커스텀 카테고리
	UE_LOG(GameObject, Warning, L"%d", InValue);
}

void CLog::Log(float InValue)
{
	UE_LOG(GameObject, Warning, L"%f", InValue);
}

void CLog::Log(const FString& InValue)
{
	UE_LOG(GameObject, Warning, L"%s", *InValue);

}

void CLog::Log(const FVector& InValue)
{
	UE_LOG(GameObject, Warning, L"%s", *InValue.ToString());

}

void CLog::Log(const FRotator& InValue)
{
	UE_LOG(GameObject, Warning, L"%s", *InValue.ToString());

}

void CLog::Log(const UObject* InObject)
{
	FString str;
	if (!!InObject)
		str.Append(InObject->GetName());

	str.Append(!!InObject ? " Not Null " : " Null ");
}

void CLog::Log(const FString& InFuncName, int32 InLineNumber)
{
	FString str;
	str.Append(InFuncName);
	str.Append(", ");
	str.Append(FString::FromInt(InLineNumber));
	UE_LOG(GameObject, Warning, L"%s", *str);
}

//void CLog::WarningLog(int32 InValue)
//{
//	UE_LOG(LogTemp, Warning, L"%d", InValue);
//}
//
//void CLog::ErrorLog(int32 InValue)
//{
//	UE_LOG(LogTemp, Error, L"%d", InValue);
//}

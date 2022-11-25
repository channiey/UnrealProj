#pragma once

#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"

class UNREALPROJ_API CHelpers
{
public:
	template<typename T> static void GetAsset(T** outObject, FString inPath)
	{
		ConstructorHelpers::FObjectFinder<T> asset(*inPath);
		verifyf(asset.Succeeded(), L"asset.Succeeded()");
		*outObject = asset.Object;
	}

	template<typename T> static void GetAssetDynamic(T** outObject, FString inPath)
	{
		T* obj = Cast<T>(StaticLoadObject(T::StaticClass(), NULL, *inPath));
		verifyf(!!obj, L"!!asset");
		*outObject = obj;
	}


	// ���Ϳ� ������Ʈ ���̱�(� ���Ϳ�, � ������Ʈ��, � �̸�����, �θ����� ����ؼ� �ٿ�����)
	template<typename T> static void CreateComponent(AActor* inActor, T** inComponent, FName inName, USceneComponent* inParent = NULL)
	{
		*inComponent = inActor->CreateDefaultSubobject<T>(inName);

		// �θ� �ִٸ� �θ� �ٿ���
		if (!!inParent)
		{
			(*inComponent)->SetupAttachment(inParent);
			return;
		}
		
		// �θ� ���ٸ� �ڱ� �ڽ��� ��Ʈ�� �����ϰ� �ٿ���
		inActor->SetRootComponent(*inComponent);
	}

	template<typename T> static void GetClass(TSubclassOf<T>* outClass, FString InPath)
	{
		ConstructorHelpers::FClassFinder<T> asset(*InPath);
		verifyf(asset.Succeeded(), L"asset.Succeeded()");
		*outClass = asset.Class;
	}
};
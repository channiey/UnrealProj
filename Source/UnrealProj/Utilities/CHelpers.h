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


	// 액터에 컴포넌트 붙이기(어떤 액터에, 어떤 컴포넌트를, 어떤 이름으로, 부모관계는 어떻게해서 붙여줄지)
	template<typename T> static void CreateComponent(AActor* inActor, T** inComponent, FName inName, USceneComponent* inParent = NULL)
	{
		*inComponent = inActor->CreateDefaultSubobject<T>(inName);

		// 부모가 있다면 부모에 붙여줌
		if (!!inParent)
		{
			(*inComponent)->SetupAttachment(inParent);
			return;
		}
		
		// 부모가 없다면 자기 자신을 루트로 설정하고 붙여줌
		inActor->SetRootComponent(*inComponent);
	}

	template<typename T> static void GetClass(TSubclassOf<T>* outClass, FString InPath)
	{
		ConstructorHelpers::FClassFinder<T> asset(*InPath);
		verifyf(asset.Succeeded(), L"asset.Succeeded()");
		*outClass = asset.Class;
	}
};
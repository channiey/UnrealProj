#include "CSpawnActor.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h" // << :

// StaticMesh'/Game/Mesh/Mesh_Cube.Mesh_Cube'
// MaterialInstanceConstant'/Game/Materials/Material_Mesh_Inst.Material_Mesh_Inst'

ACSpawnActor::ACSpawnActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	//ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(L"StaticMesh'/Game/Mesh/Mesh_Cube.Mesh_Cube'");
	//if (mesh.Succeeded())
	//{
	//	Mesh->SetStaticMesh(mesh.Object);
	//}

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Mesh/Mesh_Cube.Mesh_Cube'");
	Mesh->SetStaticMesh(mesh);
}

void ACSpawnActor::BeginPlay()
{
	Super::BeginPlay();

	/*UObject* obj = StaticLoadObject(UMaterialInstanceConstant::StaticClass(),
		NULL,
		L"MaterialInstanceConstant'/Game/Materials/Material_Mesh_Inst.Material_Mesh_Inst'"
		);

	UMaterialInstanceConstant* material = Cast<UMaterialInstanceConstant>(obj);*/

	UMaterialInstanceConstant* material;
	CHelpers::GetAssetDynamic<UMaterialInstanceConstant>(&material,
		"MaterialInstanceConstant'/Game/Materials/Material_Mesh_Inst.Material_Mesh_Inst'");

	Material = UMaterialInstanceDynamic::Create(material, this);
	Mesh->SetMaterial(0, Material);

	UKismetSystemLibrary::K2_SetTimer(this, "ChangeColor", 1.0f, true);
}

void ACSpawnActor::ChangeColor()
{
	FLinearColor color;
	color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.A = 1.0f;

	Material->SetVectorParameterValue("Color", color);
}
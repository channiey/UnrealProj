// Fill out your copyright notice in the Description page of Project Settings.


#include "CSpawnActor_Shpere.h"
#include "Global.h"

ACSpawnActor_Shpere::ACSpawnActor_Shpere()
{
	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Mesh/Mesh_Sphere.Mesh_Sphere'");
	Mesh->SetStaticMesh(mesh);
}

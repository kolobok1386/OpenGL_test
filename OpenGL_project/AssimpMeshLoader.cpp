#include "AssimpMeshLoader.h"

RTTI_DEFINITIONS(AssimpMeshLoader)

AssimpMeshLoader::AssimpMeshLoader(AKMesh& owner)
: AKMeshLoader(owner)
{

}

bool AssimpMeshLoader::loadFromFile(std::string fileName, AKMeshData& meshData)
{
	meshData.reset();

	bool Ret = false;
	Assimp::Importer Importer;

	const aiScene* pScene = Importer.ReadFile(fileName.c_str(), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs);

	if(pScene)
	{
		//Ret = InitFromScene(pScene, fileName);
	}
	else
	{
		printf("Error parsing '%s': '%s'\n", fileName.c_str(), Importer.GetErrorString());
	}

	return Ret;

}
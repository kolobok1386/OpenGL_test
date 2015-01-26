#ifndef _ASSIMP_MESH_LOADER
#define _ASSIMP_MESH_LOADER

#include "CommonInc.h"
#include "MeshLoader.h"
#include "MeshData.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class AssimpMeshLoader : public AKMeshLoader
{
	RTTI_DECLARATIONS(AssimpMeshLoader, AKMeshLoader)
public:
	AssimpMeshLoader(AKMesh& owner);
	~AssimpMeshLoader();

	virtual bool loadFromFile(std::string fileName, AKMeshData& meshData) override;


};

#endif
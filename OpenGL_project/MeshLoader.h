#ifndef _MESH_LOADER
#define _MESH_LOADER

#include "CommonInc.h"


class AKMesh;
class AKMeshData;
class AKMeshLoader : public RTTI
{
	RTTI_DECLARATIONS(AKMeshLoader, RTTI)
public:
	AKMeshLoader(AKMesh& owner);
	~AKMeshLoader();

	virtual bool loadFromFile(std::string fileName, AKMeshData& meshData) = 0;

protected:
	AKMesh& m_owner;
};

#endif
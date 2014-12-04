#ifndef _MESH
#define _MESH

#include "CommonInc.h"

class AKMesh;
class AKMeshLoader : public RTTI
{
	RTTI_DECLARATIONS(AKMeshLoader, RTTI)
public:
	AKMeshLoader(AKMesh& owner);
	~AKMeshLoader();

	virtual void loadFromFile(std::string fileName);
private:
	AKMesh& m_owner;


};

#endif
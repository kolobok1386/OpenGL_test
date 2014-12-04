#ifndef _MODEL
#define _MODEL

#include "CommonInc.h"
#include "DefTypes.h"
#include "SceneComponent.h"

class AKModel : public RTTI
{
	RTTI_DECLARATIONS(AKModel, RTTI)
public:
	AKModel(SceneComponent& owner);
	~AKModel();

	void addMesh(AKMesh* mesh);
	std::vector<AKMesh* >& getMeshes();

private:
	std::vector<AKMesh* > m_meshes;	
	SceneComponent& m_owner;

};

#endif
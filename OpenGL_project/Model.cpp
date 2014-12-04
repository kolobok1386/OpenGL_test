#include "Model.h"

RTTI_DEFINITIONS(AKModel)

AKModel::AKModel(SceneComponent& owner)
: m_owner(owner)
{

}

AKModel::~AKModel()
{

}

void AKModel::addMesh(AKMesh* mesh)
{
	m_meshes.push_back(mesh);
};

std::vector<AKMesh* >& AKModel::getMeshes()
{
	return m_meshes;
};
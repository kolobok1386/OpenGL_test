#include "MeshLoader.h"

AKMeshLoader::AKMeshLoader(AKMesh& owner)
: m_owner(owner)
{

}

AKMeshLoader::~AKMeshLoader()
{

}

void AKMeshLoader::loadFromFile(std::string fileName)
{
	if(&m_owner != nullptr)
	{

	}
	else
		throw std::exception(std::string("Owner is nullptr !!!").c_str());
}

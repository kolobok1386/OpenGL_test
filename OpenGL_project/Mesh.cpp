#include "Mesh.h"

RTTI_DEFINITIONS(AKMesh)

AKMesh::AKMesh(AKModel& owner)
: m_owner(owner)
{

}

AKMesh::~AKMesh()
{

}



void AKMesh::loadFromFile(std::string& filename)
{
	m_meshLoader->loadFromFile(filename, m_meshData);
}

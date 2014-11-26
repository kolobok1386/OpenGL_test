#include "Mesh.h"

AKMesh::AKMesh(AKModel& owner)
: m_owner(owner)
{

}

AKMesh::~AKMesh()
{

}

std::vector<glm::vec3>& AKMesh::getVertexPositions()
{
	return m_vertexPositions;
}

std::vector<glm::vec4>& AKMesh::getVertexColors()
{
	return m_vertexColors;
}

std::vector<glm::vec3>& AKMesh::getVertexNormals()
{
	return m_vertexPositions;
}

std::vector<UINT>& AKMesh::getIndices()
{
	return m_indices;
}

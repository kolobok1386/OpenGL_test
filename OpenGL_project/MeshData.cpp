#include "MeshData.h"

RTTI_DEFINITIONS(AKMeshData)
bool AKMeshData::hasVertexAttrib(int attrib)
{
	return false;
}

bool AKMeshData::init(const std::vector<glm::vec3>& positions, const std::vector<glm::vec3>& normals, const std::vector<glm::vec4>& colors, const std::vector<UINT>& indices)
{
	return true;
}

void AKMeshData::reset()
{
	m_vertexPositions.clear();
	m_vertexColors.clear();
	m_vertexNormals.clear();
	m_indices.clear();
}
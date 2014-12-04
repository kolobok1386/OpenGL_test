#include "Mesh.h"

RTTI_DEFINITIONS(AKMesh)

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

void AKMesh::loadFromFile(std::string& filename)
{
	Assimp::Importer Importer;

	const aiScene* pScene = Importer.ReadFile(filename.c_str(), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs);

	
}

#ifndef _MESH
#define _MESH

#include "CommonInc.h"
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

class AKModel;
class AKMesh : public RTTI
{
	RTTI_DECLARATIONS(AKMesh, RTTI)
public:
	AKMesh(AKModel& owner);
	~AKMesh();

	std::vector<glm::vec3>& getVertexPositions();
	std::vector<glm::vec4>& getVertexColors();
	std::vector<glm::vec3>& getVertexNormals();
	std::vector<UINT>& getIndices();

	void loadFromFile(std::string& filename);

private:
	std::vector<glm::vec3> m_vertexPositions;
	std::vector<glm::vec4> m_vertexColors;
	std::vector<glm::vec3> m_vertexNormals;
	std::vector<UINT> m_indices;
	AKModel& m_owner;


};

#endif
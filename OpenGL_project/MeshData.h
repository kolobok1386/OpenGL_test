#ifndef _MESHDATA
#define _MESHDATA

#include "CommonInc.h"

class AKMeshData : public RTTI
{
	RTTI_DECLARATIONS(AKMeshData, RTTI)
public:
	AKMeshData() : m_vertexsizeBytes(0)
	{
	}
	bool hasVertexAttrib(int attrib);
	bool init(const std::vector<glm::vec3>& positions, const std::vector<glm::vec3>& normals, const std::vector<glm::vec4>& colors, const std::vector<UINT>& indices);
	//bool init(const std::vector<float>& vertices, int vertexSizeInFloat, const std::vector<unsigned short>& indices, const std::vector<MeshVertexAttrib>& attribs);
	void reset();

protected:

	int calVertexSizeBytes();

	int m_vertexsizeBytes;
	size_t m_vertexNum;
	//std::vector<MeshVertexAttrib> m_vertexAttribs;

	std::vector<glm::vec3> m_vertexPositions;
	std::vector<glm::vec4> m_vertexColors;
	std::vector<glm::vec3> m_vertexNormals;
	std::vector<UINT> m_indices;
};

#endif
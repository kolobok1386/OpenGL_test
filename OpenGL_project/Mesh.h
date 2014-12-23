#ifndef _MESH
#define _MESH

#include "CommonInc.h"
#include "MeshLoader.h"
#include "MeshData.h"

class AKModel;
class AKMesh : public RTTI
{
	enum class IndexFormat
	{
		INDEX8 = GL_UNSIGNED_BYTE,
		INDEX16 = GL_UNSIGNED_SHORT,
	};

	enum class PrimitiveType
	{
		TRIANGLES = GL_TRIANGLES,
		TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
		LINES = GL_LINES,
		LINE_STRIP = GL_LINE_STRIP,
		POINTS = GL_POINTS
	};


	RTTI_DECLARATIONS(AKMesh, RTTI)
public:
	AKMesh(AKModel& owner);
	~AKMesh();

	void loadFromFile(std::string& filename);

private:

	AKModel& m_owner;
	AKMeshLoader* m_meshLoader;
	AKMeshData m_meshData;

};

#endif
#ifndef _GL_RENDER_OBJECT
#define _GL_RENDER_OBJECT

#include "CommonInc.h"
#include "BaseRenderObject.h"
#include "Model.h"
#include "Mesh.h"

class GLRenderObject : public BaseRenderObject
{
	RTTI_DECLARATIONS(GLRenderObject, BaseRenderObject)
public:
	GLRenderObject();
	~GLRenderObject();

	void Draw(Time& deltaTime);

//protected:
//	GLuint m_shaderId;
};

#endif
#include "GLRenderObject.h"

RTTI_DEFINITIONS(GLRenderObject)

GLRenderObject::GLRenderObject()
{

};

GLRenderObject::~GLRenderObject()
{

};

void GLRenderObject::Draw(Time& deltaTime)
{
	for(auto mesh : m_model->getMeshes())
	{
		//auto indicies = mesh->getIndices();
		//auto vertCoords = mesh->getVertexPositions();
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glUseProgram(m_program->getHandle());


	}
};
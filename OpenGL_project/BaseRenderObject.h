#ifndef _BASE_RENDER_OBJECT
#define _BASE_RENDER_OBJECT

#include "CommonInc.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Time.h"

class BaseRenderObject : public RTTI
{
	RTTI_DECLARATIONS(BaseRenderObject, RTTI)
public:
	BaseRenderObject();
	~BaseRenderObject();

	virtual void setShaderProgram(AKShaderProgram* value);
	virtual AKShaderProgram* getShaderProgram();

	virtual void setModel(AKModel* value);
	virtual AKModel* getModel();

	virtual void Draw(Time& deltaTime) = 0;

protected:
	AKModel* m_model;
	AKShaderProgram* m_program;
};

#endif
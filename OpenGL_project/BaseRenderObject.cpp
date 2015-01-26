#include "BaseRenderObject.h"

RTTI_DEFINITIONS(BaseRenderObject)

BaseRenderObject::BaseRenderObject()
{

};

BaseRenderObject::~BaseRenderObject()
{

};

void BaseRenderObject::setShaderProgram(AKShaderProgram* value)
{

};

AKShaderProgram* BaseRenderObject::getShaderProgram()
{
	return m_program;
};

void BaseRenderObject::setModel(AKModel* value)
{

};

AKModel* BaseRenderObject::getModel()
{
	return m_model;
};
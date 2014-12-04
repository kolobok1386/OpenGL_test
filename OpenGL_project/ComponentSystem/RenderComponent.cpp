#include "RenderComponent.h"

RTTI_DEFINITIONS(RenderComponent)

RenderComponent::RenderComponent()
{

}

RenderComponent::~RenderComponent()
{

}


void RenderComponent::Update(const Time& deltaTime)
{

}

BaseRenderObject* RenderComponent::getRenderObject()
{
	return m_renderObject;
}

void RenderComponent::setRenderObject(BaseRenderObject* value)
{
	m_renderObject = value;
}
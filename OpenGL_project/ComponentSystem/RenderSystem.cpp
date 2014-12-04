#include "RenderSystem.h"

RTTI_DEFINITIONS(RenderSystem)

RenderSystem::RenderSystem()
{

};

RenderSystem::~RenderSystem()
{

};

void RenderSystem::Update(const Time& deltaTime)
{
	for(auto entity : m_entities)
	{

	//	BaseComponent* posComponent = entity->getComponentByType(componentType::ctPosition).second;
	//	if(posComponent)
	//	{
	//		
	//	}

	}
};
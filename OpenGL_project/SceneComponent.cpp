#include "SceneComponent.h"

RTTI_DEFINITIONS(SceneComponent)

SceneComponent::SceneComponent()
{

}

SceneComponent::SceneComponent(Application& owner)
: m_owner(&owner),
m_renderSystem()
{

}

void SceneComponent::Init()
{

}

void SceneComponent::Update(const Time& time)
{
	if(m_renderSystem)
		m_renderSystem->Update(time);
}

Application* SceneComponent::GetOwner()
{
	return m_owner;
}

void SceneComponent::SetOwner(Application& owner)
{
	m_owner = &owner;
}
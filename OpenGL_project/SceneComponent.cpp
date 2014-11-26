#include "SceneComponent.h"

RTTI_DEFINITIONS(SceneComponent)

SceneComponent::SceneComponent()
{

}

SceneComponent::SceneComponent(Application& owner)
: m_owner(&owner)
{

}

void SceneComponent::Init()
{

}

void SceneComponent::Update(const Time& time)
{

}

Application* SceneComponent::GetOwner()
{
	return m_owner;
}

void SceneComponent::SetOwner(Application& owner)
{
	m_owner = &owner;
}
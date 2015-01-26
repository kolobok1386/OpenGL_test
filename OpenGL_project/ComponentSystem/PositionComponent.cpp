#include "PositionComponent.h"

RTTI_DEFINITIONS(PositionComponent)

PositionComponent::PositionComponent()
{

}

PositionComponent::~PositionComponent()
{

}


void PositionComponent::Update(Time& deltaTime)
{

}

glm::vec4 PositionComponent::getPosition()
{
	return m_position;
}

void PositionComponent::setPosition(glm::vec4 value)
{
	m_position = value;
}

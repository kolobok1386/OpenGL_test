#include "BaseComponent.h"

RTTI_DEFINITIONS(BaseComponent)

BaseComponent::BaseComponent()
: m_ID(""),
m_type(ctNone)
{
}

BaseComponent::~BaseComponent()
{
}

componentID BaseComponent::getID() const
{
	return m_ID;
}

void BaseComponent::setID(componentID value)
{
	m_ID = value;
}

componentType BaseComponent::getType() const
{
	return m_type;
};


#include "BaseEntity.h"

RTTI_DEFINITIONS(BaseEntity)

BaseEntity::BaseEntity()
: m_components()
{
}

BaseEntity::~BaseEntity()
{
}

BaseComponent* BaseEntity::getComponentByType(componentType type)
{
	return m_components.at(type);
}

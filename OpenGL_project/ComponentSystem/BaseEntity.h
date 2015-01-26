#ifndef _BASE_ENTITY
#define _BASE_ENTITY

#include "../CommonInc.h"
#include "../Time.h"
#include "BaseComponent.h"

class BaseEntity : public RTTI
{
	RTTI_DECLARATIONS(BaseEntity, RTTI)
public:
	BaseEntity();
	virtual ~BaseEntity();

	BaseComponent* getComponentByType(componentType type);

	virtual void Update(Time& deltaTime) = 0;
private:
	std::map<componentType, BaseComponent* > m_components;
};

#endif
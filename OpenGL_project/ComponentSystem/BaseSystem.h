#ifndef _BASE_SYSTEM
#define _BASE_SYSTEM

#include "../CommonInc.h"
#include "BaseEntity.h"

class Time;
class BaseSystem : public RTTI
{
	RTTI_DECLARATIONS(BaseSystem, RTTI)
public:
	BaseSystem();
	virtual ~BaseSystem();

	virtual void Update(Time& deltaTime) = 0;

protected:
	std::vector<std::shared_ptr<BaseEntity> > m_entities;
};

#endif
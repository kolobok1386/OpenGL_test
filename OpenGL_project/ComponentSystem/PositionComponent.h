#ifndef _POSITION_COMPONENT
#define _POSITION_COMPONENT

#include "../CommonInc.h"
#include "BaseComponent.h"

class PositionComponent : public BaseComponent
{
	RTTI_DECLARATIONS(PositionComponent, BaseComponent)
public:
	PositionComponent();
	virtual ~PositionComponent();

	virtual void Update(Time& deltaTime);

	glm::vec4 getPosition();
	void setPosition(glm::vec4 value);
private:
	glm::vec4 m_position;
};

#endif
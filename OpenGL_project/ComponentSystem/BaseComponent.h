#ifndef _BASE_COMPONENT
#define _BASE_COMPONENT

#include "../CommonInc.h"
#include "../Time.h"

enum componentType
{
	ctNone = -1,
	ctPosition = 0,
	ctMesh
};

class BaseComponent : public RTTI
{
	RTTI_DECLARATIONS(BaseComponent, RTTI)
public:
	BaseComponent();
	virtual ~BaseComponent();

	virtual componentID getID() const;
	virtual void setID(componentID value);

	virtual componentType getType() const;

	virtual void Update(Time& deltaTime) = 0;
private:
	componentID m_ID;
	componentType m_type;
};

#endif
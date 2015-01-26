#ifndef _RENDER_COMPONENT
#define _RENDER_COMPONENT

#include "../CommonInc.h"
#include "BaseComponent.h"
#include "../BaseRenderObject.h"

class RenderComponent : public BaseComponent
{
	RTTI_DECLARATIONS(RenderComponent, BaseComponent)
public:
	RenderComponent();
	virtual ~RenderComponent();

	virtual void Update(const Time& deltaTime);

	BaseRenderObject* getRenderObject();
	void setRenderObject(BaseRenderObject* value);
private:
	BaseRenderObject* m_renderObject;
};

#endif
#ifndef _RENDER_SYSTEM
#define _RENDER_SYSTEM

#include "BaseSystem.h"
#include "BaseComponent.h"
#include "../BaseRenderObject.h"

class RenderSystem : public BaseSystem
{
	RTTI_DECLARATIONS(RenderSystem, BaseSystem)
public:
	RenderSystem();
	virtual ~RenderSystem();

	virtual void Update(const Time& deltaTime);

private:
	std::unordered_map<BaseEntity*, BaseRenderObject* > m_entities;
};

#endif
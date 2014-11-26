#ifndef SCENE_COMPONENT_H
#define SCENE_COMPONENT_H

#include "CommonInc.h"
#include "Time.h"

class Application;
class Time;

class SceneComponent : public RTTI
{
	RTTI_DECLARATIONS(SceneComponent, RTTI)
public:
	SceneComponent();
	SceneComponent(Application& owner);

	Application* GetOwner();
	void SetOwner(Application& owner);

	virtual void Init();
	virtual void Update(const Time& time);

protected:
	Application* m_owner;
};

#endif
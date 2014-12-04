#ifndef APPLICATION_H
#define APPLICATION_H

#include "CommonInc.h"
#include "Time.h"
#include "GameClock.h"
#include "SceneComponent.h"
#include "ApplicationWindow.h"


class Application : public RTTI
{
	RTTI_DECLARATIONS(Application, RTTI)
public:
	Application();
	virtual ~Application();

	virtual void Init();
	virtual void Run();
	virtual void Exit();
	virtual void Draw(const Time& time);
	virtual void Update(const Time& time);

protected:
	virtual void InitWindow();

private:
	Time m_appTime;
	GameClock m_appClock;
	bool m_isFullScreen;
	ApplicationWindow m_mainWindow;
	int m_screenWidth;
	int m_screenHeight;
	SceneComponent* m_scene;
};


#endif
#include "Application.h"
#include "GLFW/glfw3native.h"

RTTI_DEFINITIONS(Application)

Application::Application()
: m_appClock(),
m_appTime(),
m_mainWindow(800, 600, L"Trololo", false),
m_scene()
{

}

Application::~Application()
{
	DELETE_PTR(m_scene);
}

void Application::Init()
{
	InitWindow();
}

void Application::Run()
{
	Init();
	while(!glfwWindowShouldClose(m_mainWindow.getWnd()))
	{
		m_appClock.UpdateGameTime(m_appTime);
		Update(m_appTime);
		Draw(m_appTime);

		glfwPollEvents();
	}
}

void Application::Exit()
{

}

void Application::Draw(const Time& time)
{

}

void Application::Update(const Time& time)
{
	if(m_scene)
		m_scene->Update(time);
}

void Application::InitWindow()
{
	m_mainWindow.Init();
}
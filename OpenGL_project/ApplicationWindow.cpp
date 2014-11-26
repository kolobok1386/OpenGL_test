#include "ApplicationWindow.h"

ApplicationWindow::ApplicationWindow()
{

};

ApplicationWindow::ApplicationWindow(int width, int height, const std::wstring& windowTitle, bool isFullScreen)
: m_width(width),
m_height(height),
m_windowTitle(windowTitle),
m_isFullScreen(isFullScreen)
{

};

ApplicationWindow::~ApplicationWindow()
{

}

void ApplicationWindow::Init()
{
	if(!glfwInit())
	{
		//throw GameException("glfwInit() failed.");
	}

	GLFWmonitor* monitor = (m_isFullScreen ? glfwGetPrimaryMonitor() : nullptr);
	m_window = glfwCreateWindow(m_width, m_height, ("Trololo")/*Utility::ToString(m_windowTitle).c_str()*/, monitor, nullptr);
	if(m_window == nullptr)
	{
		//Shutdown();
		//throw GameException("glfwCreateWindow() failed.");
	}

	POINT center = CenterWindow(m_width, m_height);
	glfwSetWindowPos(m_window, center.x, center.y);
}

POINT ApplicationWindow::CenterWindow(int windowWidth, int windowHeight)
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	POINT center;
	center.x = (screenWidth - windowWidth) / 2;
	center.y = (screenHeight - windowHeight) / 2;

	return center;
}
#ifndef APPLICATION_WINDOW_H
#define APPLICATION_WINDOW_H

#include "CommonInc.h"

class Application;
class ApplicationWindow
{
public:
	ApplicationWindow();
	ApplicationWindow(int width, int height, const std::wstring& windowTitle, bool isFullScreen);

	virtual ~ApplicationWindow();

	GLFWwindow* getWnd() { return m_window;	};

	void Init();

protected:
	POINT CenterWindow(int windowWidth, int windowHeight);

private:
	int m_width;
	int m_height;
	std::wstring m_windowTitle;
	GLFWwindow* m_window;
	bool m_isFullScreen;
};

#endif

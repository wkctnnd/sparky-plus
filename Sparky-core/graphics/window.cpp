#include "window.h"
#include <iostream>
#include "input/input.h"

namespace sparky {
	namespace graphics {
		//bool Window::Keys[MAX_KEYS];
		//bool Window::MouseButtons[Max_BUTTONS];
		//double Window::mx;
		//double Window::my;
		//void WindowResize(GLFWwindow* window, int width, int height);
	
		Window::Window(const char*name, int width, int height)
		{
			m_Title = name;
			m_Width = width;
			m_Height = height;
			if (!init())
			{
				glfwTerminate();
			}
			//INSTANCE = this;

			for (int i=0; i<MAX_KEYS;i++)
			{
				Keys[i] = false;
			}
			for (int i = 0; i < Max_BUTTONS; i++)
			{
				MouseButtons[i] = false;
			}
		}
		Window::~Window()
		{

		}

		//void Window::clear()const
		//{
		//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//}

		//bool Window::Closed()const
		//{
		//	//return glfwWindowShouldClose(m_Window);
		//}

		bool Window::isKeyPress(unsigned int keycode)
		{
			if (keycode < MAX_KEYS)
			{
				return Keys[keycode];
			}
			return false;
		}

		bool Window::init()
		{
		
			return true;
		}

		bool Window::isMouseButtonPress(unsigned int buttoncode)
		{
			if (buttoncode < Max_BUTTONS)
			{
				return MouseButtons[buttoncode];
			}
			return false;
		}

	 

		//void WindowResize(GLFWwindow* window, int width, int height)
		//{
		//	//glViewport(0, 0, width, height);
		//}

		
} }
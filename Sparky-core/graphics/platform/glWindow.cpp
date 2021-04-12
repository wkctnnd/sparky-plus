#include "glwindow.h"
#include <iostream>
#include "input/input.h"
#include "ui/uimanager.h"
namespace sparky {
	namespace graphics {
		//bool Window::Keys[MAX_KEYS];
		//bool Window::MouseButtons[Max_BUTTONS];
		//double Window::mx;
		//double Window::my;
		void WindowResize(GLFWwindow* window, int width, int height);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->Keys[key] = action != GLFW_RELEASE;
		}
		void mouse_button_callback(GLFWwindow* window, int key, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->MouseButtons[key] = action != GLFW_RELEASE;

			sparky::input::InputManager::SetMouseActionState(key, action);
		}

		void mouse_position_callback(GLFWwindow* window, double x, double y)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = x;
			win->my = y;

			sparky::input::InputManager::SetMouseMoveState(x, y);
		}
		GLWindow::GLWindow(const char*name, int width, int height):Window(name, width, height)
		{
			if (!init())
			{
				glfwTerminate();
			}
			//INSTANCE = this;

			for (int i = 0; i < MAX_KEYS; i++)
			{
				Keys[i] = false;
			}
			for (int i = 0; i < Max_BUTTONS; i++)
			{
				MouseButtons[i] = false;
			}
		}
		GLWindow::~GLWindow()
		{

		}

		void GLWindow::clear()const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool GLWindow::Closed()const
		{
			return glfwWindowShouldClose(m_Window);
		}

	
		bool GLWindow::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to Init GLFW!" << std::endl;
				return false;
			}
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			WindowResize(m_Window, m_Width, m_Height);
			if (!m_Window)
			{
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, WindowResize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, mouse_position_callback);
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}
			std::cout << "Openg Version is" << glGetString(GL_VERSION) << std::endl;
			return true;
		}

		
		void GLWindow::update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);

			glfwSwapBuffers(m_Window);
		}

		void WindowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}


	}
}
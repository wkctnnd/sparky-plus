#include "application.h"

#include "graphics/window.h"
#include "maths/vec2.h"
#include "utils/fileutils.h"
#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/computeshader.h"
#include "render/FluidRenderer.h"
#include "render/mesh.h"
#include "utils/timer.h"
#include "engine.h"
#include "graphics/platform/glwindow.h"

 

#include "input/input.h"

using namespace sparky::input;
using namespace sparky::graphics;

namespace sparky
{
	void Application::Initialize()
	{
		m_Engine = new Engine();
		m_Window = new GLWindow("Sparky!", 1920, 1080);
	}


	void Application::Run()
	{
		while (!m_Window->Closed())
		{
			glClearColor(1, 1, 1, 1);
			m_Window->clear();
			//std::cout << window.getHeight() << "," << window.getWidth()<<std::endl;
			//std::cout << vector;
			if (m_Window->isKeyPress(GLFW_KEY_W))
			{
				InputManager::SetKey(KEY_W, true);
			}
			if (m_Window->isKeyPress(GLFW_KEY_V))
			{
				InputManager::SetKey(KEY_V, true);
			}

			else if (m_Window->isKeyPress(GLFW_KEY_A))
			{
				InputManager::SetKey(KEY_A, true);
			}
			else if (m_Window->isKeyPress(GLFW_KEY_S))
			{
				InputManager::SetKey(KEY_S, true);
			}
			else if (m_Window->isKeyPress(GLFW_KEY_D))
			{
				InputManager::SetKey(KEY_D, true);
			}



			if (m_Window->isMouseButtonPress(GLFW_MOUSE_BUTTON_LEFT))
			{
				std::cout << "mouse press!";
			}

			m_Engine->Loop();
			m_Engine->PostRender();
			m_Window->update();


		}
	}
}
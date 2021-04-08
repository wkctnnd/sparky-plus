#pragma once
#include "graphics/window.h"

namespace sparky {
	namespace graphics {

#define MAX_KEYS 1024
#define Max_BUTTONS 10
		class GLWindow:public Window
		{

		public:
		 

		private:
		 
			GLFWwindow* m_Window;

			bool MouseButtons[Max_BUTTONS];
			bool Keys[MAX_KEYS];
			double mx, my;
			bool m_Closed;

		public:
			GLWindow(const char*name, int width, int height);
			void clear() const;
			~GLWindow();
			void update();
			bool Closed()const;

		private:
			bool init();
			//static void key_callback(GLFWwindow* window, int )
			//void WindowResize(GLFWwindow* window, int width, int height);
		};

	}

}
#pragma once
#include <gl/glew.h>
#include <glfw/glfw3.h>

namespace sparky {
	namespace graphics {

#define MAX_KEYS 1024
#define Max_BUTTONS 10
		class Window
		{
			friend void key_callback(GLFWwindow* window, int, int, int, int);
			friend void mouse_button_callback(GLFWwindow* window, int, int, int);
			friend void mouse_position_callback(GLFWwindow* window, double, double);
		public:

		
			
		protected:
			const char* m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
			
			 bool MouseButtons[Max_BUTTONS];
			 bool Keys[MAX_KEYS];
			 double mx, my;
			bool m_Closed;
			
		public:
			
			virtual void clear() const = 0;
			
			virtual void update() = 0;
			virtual bool Closed()const = 0;

			

		public:
			Window(const char*name, int width, int height);
			~Window();
			
			inline int getWidth()const { return m_Width; }
			int getHeight()const { return m_Height; }

			bool isKeyPress(unsigned int keycode);
			bool isMouseButtonPress(unsigned int buttoncode);
			virtual void* GetNativeWindow() { return 0; };
		private:
			bool init();
			//static void key_callback(GLFWwindow* window, int )
			//void WindowResize(GLFWwindow* window, int width, int height);
		};

}

}
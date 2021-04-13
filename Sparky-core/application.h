#pragma once


namespace sparky
{
	class Engine;
	namespace graphics
	{
		class Window;
	}
}
using namespace sparky::graphics;
namespace sparky
{
	class Application
	{
	public:

		static Application* app;

		static Application* Get()
		{
			if (!app)
				app = new Application();
			return app;
		}

		void Initialize();

		void Run();

		graphics::Window * GetWindow()
		{
			return m_Window;
		}
	private:

		Application()
		{

		}
		
		graphics::Window * m_Window;
		sparky::Engine* m_Engine;
	};

	//Application* Application::app = 0;
}
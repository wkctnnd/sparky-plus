#pragma once



namespace sparky
{
 

	class Application
	{
	public:
		void Initialize();

	private:
		class Engine* m_Engine;
		class Window * m_Window;
	};
}
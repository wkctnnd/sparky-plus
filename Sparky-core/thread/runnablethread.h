#pragma once
namespace sparky
{
	namespace thread
	{
		class RunnableThread
		{
		public:
			virtual void Run();
			static RunnableThread* CreateThread();
		};
	}
}
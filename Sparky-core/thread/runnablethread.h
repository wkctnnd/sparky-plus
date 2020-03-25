#pragma once
#include <thread>

namespace sparky
{
	namespace thread
	{
		class Runnable;
		class RunnableThread
		{
		public:
			virtual void Run();
			static RunnableThread* CreateThread(Runnable* rannable);


		private:
			RunnableThread(Runnable* rannable);

			std::thread *m_Thread;
			Runnable *m_Runnable;
		};
	}
}
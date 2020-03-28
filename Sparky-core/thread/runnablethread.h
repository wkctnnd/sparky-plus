#pragma once
#include <thread>

namespace sparky
{
	namespace thread
	{
		class Runnable;
		class ThreadPool;
		class RunnableThread
		{
		public:
			virtual void Run();
			static RunnableThread* CreateThread(void *func£¨£©, ThreadPool* pool);
			RunnableThread(void *func, ThreadPool* pool);

		private:
			

			std::thread m_Thread;
			Runnable *m_Runnable;
		};
	}
}
#pragma once
#include "runnable.h"
namespace sparky
{
	namespace thread
	{
		class QueuedThread :public Runnable
		{
		public:
			QueuedThread(class ThreadPool* pool);

			virtual void Run();
			virtual void Stop();
			virtual void Init();
			virtual void Exit();
			virtual void DoWork(Walkable* work);

		private:
			class RunnableThread* m_RunnableThread;
			class ThreadPool* m_ThreadPool;
		};
	}
}
#pragma once
#include <vector>
#include <queue>
#include <condition_variable>
#include <mutex>
//https://blog.csdn.net/mayue_web/article/details/83097416
namespace sparky
{
	namespace thread
	{
		
		class ThreadPool
		{
		public:
			void Initialize(unsigned int size);
			void PushWorker(class Workable* work, void(*function) = 0);

			void Update(Runnable* runnable);
		private:
			std::vector<class QueuedThread*> m_Threads;
			std::queue<class Walkable*> m_Works;

			std::condition_variable m_WorkTodo;

			std::vector<class QueuedThread*> m_RunningThreads;
			std::mutex m_Mutex;
			std::mutex m_WorkListMutex;
			bool IsWorkReady;
		};
	}
}
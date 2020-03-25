#pragma once
#include <vector>
#include <queue>
namespace sparky
{
	namespace thread
	{
		
		class ThreadPool
		{
		public:
			void PushWorker(class Workable* work);

		private:
			std::vector<class QueuedThread*> m_Threads;
			std::queue<class Walkable*> m_Works;
		};
	}
}
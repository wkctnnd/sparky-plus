#pragma once
#include <vector>
namespace sparky
{
	namespace thread
	{
		
		class ThreadPool
		{
		public:
			void PushWorker(class Work* work);
		private:
			std::vector<class QueuedThread*> m_Threads;
			std::vector<>
		};
	}
}
#pragma once
#include "threadpool.h"
#include <vector>
#include <queue>
#include <condition_variable>
#include "threadpool.h"

namespace sparky
{
	namespace thread
	{

		void ThreadPool::Initialize(unsigned int size)
		{
			bool IsWorkReady = false;

			for (unsigned int i = 0; i < size; i++)
			{
				m_Threads = new QueuedThread();
			}
		 
		}

		void ThreadPool::PushWorker(class Workable* work, void(*function))
		{
			std::unique_lock<std::mutex> locker(m_WorkListMutex);
			locker.lock();
			m_Works.push(work);
			locker.unlock();
		}
		void ThreadPool::Update()
		{
			std::unique_lock<std::mutex> lock(m_Mutex);
			while (!IsWorkReady) m_WorkTodo.wait(lock);


			
		}
		 
	

	}
}
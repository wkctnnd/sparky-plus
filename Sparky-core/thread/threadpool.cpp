#pragma once
#include "threadpool.h"
#include <vector>
#include <queue>
#include <condition_variable>
#include "threadpool.h"
#include "queuedthread.h"
namespace sparky
{
	namespace thread
	{

		void ThreadPool::Initialize(unsigned int size)
		{
			bool IsWorkReady = false;

			for (unsigned int i = 0; i < size; i++)
			{
				m_Threads = new QueuedThread(ThreadPool::Update, this);
			}
		 
		}

		void ThreadPool::PushWorker(class Workable* work, void(*function))
		{
			std::unique_lock<std::mutex> locker(m_WorkListMutex);
			locker.lock();
			m_Works.push(work);
			locker.unlock();

			m_WorkTodo.notify_one();
		}


		void ThreadPool::Update(Runnable *runnable)
		{
			std::mutex Mutex;
			std::unique_lock<std::mutex> lock(Mutex);
			while (!IsWorkReady) m_WorkTodo.wait(lock);

			std::unique_lock<std::mutex> worklocker(m_WorkListMutex);
			worklocker.lock();
			Walkable* work = m_Works.front();
			m_Works.pop();
			
			worklocker.unlock();
			lock.unlock();

			runnable->Run(work);
		}
		 
	

	}
}
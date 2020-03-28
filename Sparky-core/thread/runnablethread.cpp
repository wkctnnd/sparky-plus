#pragma once
#include "runnablethread.h"
#include "runnable.h"
#include <thread>
#include "threadpool.h"
namespace sparky
{
	namespace thread
	{
	
		void RunnableThread::Run()
		{

		}

		RunnableThread* RunnableThread::CreateThread(void* func£¨£©, ThreadPool* pool)
		{
			RunnableThread* newThread = new RunnableThread(func, pool);
			//m_Runnable = runnable;
			return newThread;
		}


		RunnableThread::RunnableThread(void *func, ThreadPool* pool)
		{
			m_Thread = std::thread(func, pool);
		}



	
	}
}
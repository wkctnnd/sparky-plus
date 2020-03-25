#pragma once
#include "runnablethread.h"
#include "runnable.h"
#include <thread>
namespace sparky
{
	namespace thread
	{
	
		void RunnableThread::Run()
		{

		}

		RunnableThread* RunnableThread::CreateThread(Runnable* runnable)
		{
			RunnableThread* newThread = new RunnableThread(runnable);
			//m_Runnable = runnable;
			return newThread;
		}


		RunnableThread::RunnableThread(Runnable* runnable)
		{

		}
	
	}
}
#include "queuedthread.h"
#include "workable.h"
#include "threadpool.h"
#include "runnablethread.h"
namespace sparky
{
	namespace thread
	{
		QueuedThread::QueuedThread(class ThreadPool* pool)
		{
			m_RunnableThread = RunnableThread::CreateThread(QueuedThread::Run, this);
		}

		void QueuedThread::Run()
		{
			m_ThreadPool->Update(this);
		}

		void QueuedThread::DoWork(Walkable* work)
		{

		}


		void QueuedThread::Stop()
		{

		}
		void QueuedThread::Init()
		{

		}
		void QueuedThread::Exit()
		{

		}
	}
}
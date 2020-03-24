#pragma once
#include "runnable.h"
namespace sparky
{
	namespace thread
	{
		class QueuedThread :public Runnable
		{
		public:
			virtual void Run();
			virtual void Stop();
			virtual void Init();
			virtual void Exit();
		};
	}
}
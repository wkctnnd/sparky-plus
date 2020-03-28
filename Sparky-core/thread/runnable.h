#pragma once
namespace sparky
{
	namespace thread
	{
		class Runnable
		{
		public:
			virtual void Run(class Walkable*) = 0;
			virtual void Stop() = 0;
			virtual void Init() = 0;
			virtual void Exit() = 0;

		protected:
			class RunnableThread* thread;
		};
	}
}
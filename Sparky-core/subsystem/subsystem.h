#pragma once
namespace sparky
{
	namespace subsystem
	{
		class ISubSystem
		{
		public:
			virtual void StartUp() = 0;
			virtual void ShutDown() = 0;
		};
	}
}


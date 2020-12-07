#pragma once
#include <vector>
namespace sparky
{
	namespace world
	{
		class Actor;
	}
	namespace game
	{
		class GameInstance
		{
		public:
			virtual void Init() = 0;
			virtual void Update() = 0;

		private:

		
		};
	}
}

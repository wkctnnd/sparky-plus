#pragma once

#include "controller.h"
#include "utils/random.h"
namespace sparky
{
	namespace game
	{
		class RobotController :public Controller
		{
		public:

			void Update();


		private:
			float3 GetRandomDirection();
			Random m_RandomEngine;
		};
	}
}
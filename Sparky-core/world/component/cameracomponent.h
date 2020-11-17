#pragma once
#include "ecs/component.h"
#include "maths/mat4.h"
using namespace sparky::maths;
namespace sparky
{
	namespace world
	{
		class CameraComponnet :public Component
		{
		public:
			mat4 GetProjectionMatrix();
			mat4 GetViewMatrix();


		private:
			float m_Fov;
			float m_Aspect;
			float m_Width;
		};
	}
}

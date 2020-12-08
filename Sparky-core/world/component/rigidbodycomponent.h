#pragma once
#include "component.h"
#include "maths/mat4.h"
using namespace sparky::maths;
namespace sparky
{

	namespace world
	{
		class RigidBodyComponent :public Component
		{
		public:
			static ComponentType TYPE;
			RigidBodyComponent(Actor *owner);
		

		private:
			float m_Fov;
			float m_Aspect;
			float m_Width;

			float m_Far;
			//graphics::View* m_View;
			graphics::RenderTargetInfo* m_RtInfo;
		};

		
	}
}

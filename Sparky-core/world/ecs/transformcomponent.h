#pragma once
#include "component.h"
#include "maths/vec3.h"
#include "maths/quaternion.h"
using namespace sparky::maths;
namespace sparky
{
	namespace ecs
	{
		class TransformComponent : public IComponent
		{
		public:
			

			void SetPosition(float3& position);
			void SetRotation(Quaternion& q);
			void SetScale(float3& scale);

		private:
			float3 m_Position;
			Quaternion m_Rotation;
			float3 m_Scale;
		};
	}
}
#pragma once
#include "maths/vec3.h"
#include "component.h"
#include "maths/quaternion.h"
#include "maths/mat4.h"
using namespace sparky::maths;
namespace sparky
{
	namespace world
	{
		class Actor;
		class TransformComponent :public Component
		{
			mat4 GetLocalTransform();
			mat4 GetWorldTransform();


			float3 GetWorldPosition();
			float3 GetWorldRotation();
			float3 GetWorldScale();

			void Translate(float3 T);
			void RotateXAxis(float angle);
			void RotateYAxis(float angle);
			void RotateZAxis(float angle);


			void RotateFromQuat(Quaternion quat);
			
			void AttachTo(TransformComponent& component);
			void DetachTo(TransformComponent& component);
			void SetParent(TransformComponent& component);
		private:
			float3 m_Position;
			Quaternion m_Rotation;
			float3 m_Scale;

			std::vector<TransformComponent*> m_Children;
			TransformComponent* m_Parent;

			
		};
	}
}

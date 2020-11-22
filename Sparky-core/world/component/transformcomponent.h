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
		public:

			static ComponentType TYPE;

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

			int GetChildCount() { return m_Children.size(); }
			TransformComponent* GetChild(int i) { return m_Children[i]; }
			float3 Forward() {
				return m_Forward;
			}
			float3 Right() 
			{
				return m_Right;
			}
			float3 Up() 
			{
				return m_Up;
			}
			
			void Update();
			ComponentType GetType()
			{
				return ComponentType::TRANSFORM_TYPE;
			}
		private:
			float3 m_Position;
			Quaternion m_Rotation;
			float3 m_Scale;

			std::vector<TransformComponent*> m_Children;
			TransformComponent* m_Parent;

			float3 m_Forward;
			float3 m_Up;
			float3 m_Right;

			bool m_Dirty;
			
		};

		ComponentType CameraComponnet::TYPE = ComponentType::TRANSFORM_TYPE;
	}
}


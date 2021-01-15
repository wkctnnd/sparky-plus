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
			TransformComponent(Actor* owner);
			static ComponentType TYPE;

			mat4 GetLocalTransform();
			mat4 GetWorldTransform();

			void SetWorldPosition(float3 wp);

			float3 GetWorldPosition();
			float3 GetWorldRotation();
			float3 GetWorldScale();

			float3 GetLocalPosition();
			float3 GetLocalRotation();
			float3 GetLocalScale();

			void SetLocalPosition(float3 position);
			void SetLocalRotation(float3 rotate);
			void SetLocalScale(float3 scale);

			void Translate(float3 T);
			void RotateXAxis(float angle);
			void RotateYAxis(float angle);
			void RotateZAxis(float angle);
			void Rotate(float angle, float3 Axis);
			void RotateForwardTo(float3 Axis);
			virtual void PreUpdate() {}
			void Update();
			virtual void PostUpdate() {}

			void UpdateChain();
			void UpdateChainAsyn();
			void RotateFromQuat(Quaternion quat);
			
			void AttachTo(TransformComponent& component);
			void Attach(TransformComponent& component);
			void Detach(TransformComponent& component);
			void SetParent(TransformComponent& component);
			TransformComponent* GetParent() { return m_Parent; }

			int GetChildCount() { return m_Children.size(); }
			TransformComponent* GetChild(int i) { return m_Children[i]; }
			float3 Forward() {
				
				m_Forward.x = m_WorldMatrix.GetElement(8);
				m_Forward.y = m_WorldMatrix.GetElement(9);
				m_Forward.z = m_WorldMatrix.GetElement(10);
				return m_Forward;

			}
			float3 Right() 
			{
				m_Right.x = m_WorldMatrix.GetElement(0);
				m_Right.y = m_WorldMatrix.GetElement(1);
				m_Right.z = m_WorldMatrix.GetElement(2);
				return m_Right;
			}
			float3 Up() 
			{
				return m_Up;
			}
			
			 
			ComponentType GetType()
			{
				return ComponentType::TRANSFORM_TYPE;
			}

		private:
			float3 m_WorldPosition;
			Quaternion m_WorldRotation;
			float3 m_WorldScale;


			float3 m_LocalPosition;
			Quaternion m_LocalRotation;
			float3 m_LocalScale;

			

			std::vector<TransformComponent*> m_Children;
			TransformComponent* m_Parent;

			float3 m_Forward;
			float3 m_Up;
			float3 m_Right;
			
			mat4 m_WorldMatrix;
			mat4 m_LocalTransform;
			bool m_Dirty;
			
		};

		
	}
}


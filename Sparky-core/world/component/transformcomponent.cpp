#pragma once
#include "transformcomponent.h"
#include "maths/util.h"
using namespace sparky::maths;
namespace sparky
{
	namespace world
	{
		ComponentType TransformComponent::TYPE = ComponentType::TRANSFORM_TYPE;

		TransformComponent::TransformComponent(Actor* owner) :Component(owner),m_LocalPosition(0,0,0),m_LocalRotation(0,0,0,1),m_LocalScale(1,1,1)
		{
			
		}

		mat4 TransformComponent::GetLocalTransform()
		{
			return m_LocalTransform;
		}
		mat4 TransformComponent::GetWorldTransform()
		{
			return m_WorldMatrix;
		}


		float3 TransformComponent::GetWorldPosition()
		{
			return float3(0, 0, 0);
		}
		float3 TransformComponent::GetWorldRotation()
		{
			return float3(0, 0, 0);
		}
		float3 TransformComponent::GetWorldScale()
		{
			return float3(0, 0, 0);
		}

		void TransformComponent::Translate(float3 T)
		{
			m_LocalPosition += T;
		}
		void TransformComponent::RotateXAxis(float angle)
		{
			Quaternion r = Quaternion::FromEulerXYZ(angle, 0, 0);
			m_LocalRotation *= r;
			//m_Rotation
		}
		void TransformComponent::RotateYAxis(float angle)
		{
			Quaternion r = Quaternion::FromEulerXYZ(0, angle, 0);
			m_LocalRotation *= r;
		}
		void TransformComponent::RotateZAxis(float angle)
		{
			Quaternion r = Quaternion::FromEulerXYZ(0, 0, angle);
			m_LocalRotation *= r;
			
		}
		void TransformComponent::Rotate(float angle, float3 Axis)
		{
			Quaternion r = Quaternion::FromEulerAnyAxis(angle, Axis);
			m_LocalRotation *= r;
		}

		void TransformComponent::RotateForwardTo(float3 Axis)
		{
			float3 nAxis = Axis.Normalize();
			float3 rotateAxis = m_Forward.Cross(Axis);
			float angle = maths::Util::ArcSin(m_Forward.Dot(nAxis));
			Rotate(angle, rotateAxis);
			 
		}


		void TransformComponent::SetLocalPosition(float3 position)
		{
			m_LocalPosition = position;
		}
		void TransformComponent::SetLocalRotation(float3 rotate)
		{
			m_LocalRotation = Quaternion::FromEulerXYZ(rotate.x, rotate.y, rotate.z);
 
		}
		void TransformComponent::SetLocalScale(float3 scale)
		{
			m_LocalScale = scale;
		}


		void TransformComponent::SetWorldPosition(float3 wp)
		{
			m_WorldPosition = wp;
		}

		void TransformComponent::RotateFromQuat(Quaternion quat)
		{

		}

		void TransformComponent::AttachTo(TransformComponent& component)
		{
			m_Children.push_back(&component);
			component.SetParent(*this);
		}
		void TransformComponent::DetachTo(TransformComponent& component)
		{
			for (int i=0;i<m_Children.size();i++)
			{
				if (&component == m_Children[i])
				{
					m_Children.erase(m_Children.begin() + i);
				}
			}
		}

		void TransformComponent::SetParent(TransformComponent& component)
		{
			m_Parent = &component;
		}

		//更新worldmat和forward right up的向量
		void TransformComponent::Update()
		{
			if (m_Dirty)
			{
				mat4 worldtrans = GetWorldTransform();
				m_Forward.x = worldtrans.elements[0];
				m_Forward.y = worldtrans.elements[1];
				m_Forward.z = worldtrans.elements[2];

				m_Right.x = worldtrans.elements[4];
				m_Right.y = worldtrans.elements[5];
				m_Right.z = worldtrans.elements[6];

				m_Up.x = worldtrans.elements[8];
				m_Up.y = worldtrans.elements[9];
				m_Up.z = worldtrans.elements[10];
			}
		}


		void TransformComponent::UpdateChain()
		{
			m_LocalTransform = mat4::Translate(m_LocalPosition)*mat4::rotation(m_LocalRotation)*mat4::scale(m_LocalScale);
			if (m_Parent == 0)
			{
			
				m_WorldMatrix = m_LocalTransform;
			}
			else
			{
				m_WorldMatrix = m_Parent->GetWorldTransform()*m_LocalTransform;
			}

			for (int i=0;i<m_Children.size();i++)
			{
				m_Children[i]->UpdateChain();
			}
		}

		void TransformComponent::UpdateChainAsyn()
		{

		}
 
	}
}


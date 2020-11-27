#pragma once
#include "transformcomponent.h"

using namespace sparky::maths;
namespace sparky
{
	namespace world
	{
		ComponentType TransformComponent::TYPE = ComponentType::TRANSFORM_TYPE;
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
			m_Position += T;
		}
		void TransformComponent::RotateXAxis(float angle)
		{
			m_Rotation
		}
		void TransformComponent::RotateYAxis(float angle)
		{

		}
		void TransformComponent::RotateZAxis(float angle)
		{

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
			m_LocalTransform = mat4::Translate(m_Position)*mat4::rotation(m_Rotation)*mat4::scale(m_Scale);
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


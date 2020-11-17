#pragma once
#include "transformcomponent.h"
using namespace sparky::maths;
namespace sparky
{
	namespace world
	{

		mat4 TransformComponent::GetLocalTransform()
		{

		}
		mat4 TransformComponent::GetWorldTransform()
		{

		}


		float3 TransformComponent::GetWorldPosition()
		{

		}
		float3 TransformComponent::GetWorldRotation()
		{

		}
		float3 TransformComponent::GetWorldScale()
		{

		}

		void TransformComponent::Translate(float3 T)
		{

		}
		void TransformComponent::RotateXAxis(float angle)
		{

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
	}
}


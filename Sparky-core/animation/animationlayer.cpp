#pragma once
#include "animationlayer.h"

namespace sparky
{
	namespace animation
	{


		bool AnimationLayer::GetLoop() const
		{

		}
		void AnimationLayer::SetLoop(bool loop)
		{

		}

		void AnimationLayer::SetWeight(float weight)
		{

		}

		bool AnimationLayer::GetWeight()const
		{

		}

		std::vector<Interpolator<float>*>  AnimationLayer::GetFloatInterpolator()
		{
			std::vector<Interpolator<float>*> interpolator;
			for (unsigned int i = 0; i < m_FloatProperties.size(); i++)
			{
				interpolator.push_back((*m_FloatProperties[i])->GetInterpolator()); 
			}
			return interpolator;
		}

		std::vector<Interpolator<vec3>*>  AnimationLayer::GetVec3Interpolator()
		{
			std::vector<Interpolator<vec3>*> interpolator;
			for (unsigned int i = 0; i < m_Vec3Properties.size(); i++)
			{
				interpolator.push_back((*m_Vec3Properties[i])->GetInterpolator());
			}
			return interpolator;
		}

		std::vector<Interpolator<Quaternion>*>  AnimationLayer::GetQuatInterpolator()
		{
			std::vector<Interpolator<Quaternion>*> interpolator;
			for (unsigned int i = 0; i < m_QuatProperties.size(); i++)
			{
				interpolator.push_back((*m_QuatProperties[i])->GetInterpolator());
			}
			return interpolator;
		}

	}
}
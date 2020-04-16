#pragma once
#include "animationlayer.h"

namespace sparky
{
	namespace animation
	{


		bool AnimationLayer::GetLoop() const
		{
			return false;
		}
		void AnimationLayer::SetLoop(bool loop)
		{

		}

		void AnimationLayer::SetWeight(float weight)
		{

		}

		bool AnimationLayer::GetWeight()const
		{
			return false;
		}

		/*std::vector<Interpolator<float>*>  AnimationLayer::GetFloatInterpolator()
		{
			std::vector<Interpolator<float>*> interpolator;
			for (unsigned int i = 0; i < m_FloatProperties.size(); i++)
			{
				auto temp = m_FloatProperties[i]->GetInterpolator(m_FloatProperties[i]);
				interpolator.push_back(temp);
			}
			return interpolator;
		}

		std::vector<Interpolator<vec3>*>  AnimationLayer::GetVec3Interpolator()
		{
			std::vector<Interpolator<vec3>*> interpolator;
			for (unsigned int i = 0; i < m_Vec3Properties.size(); i++)
			{
				interpolator.push_back(m_Vec3Properties[i]->GetInterpolator(m_Vec3Properties[i]));
			}
			return interpolator;
		}

		std::vector<Interpolator<Quaternion>*>  AnimationLayer::GetQuatInterpolator()
		{
			std::vector<Interpolator<Quaternion>*> interpolator;
			for (unsigned int i = 0; i < m_QuatProperties.size(); i++)
			{
				interpolator.push_back(m_QuatProperties[i]->GetInterpolator(m_QuatProperties[i]));
			}
			return interpolator;
		}*/


		std::vector<InterpolatorBase*> AnimationLayer::GetInterPolator()
		{
			std::vector<InterpolatorBase*> interpolator;
			//for (unsigned int i = 0; i < m_FloatProperties.size(); i++)
			//{
			//	auto temp = m_FloatProperties[i]->GetInterpolator(m_FloatProperties[i]);
			//	//interpolator.push_back(temp);
			//}
 
			//for (unsigned int i = 0; i < m_QuatProperties.size(); i++)
			//{
			//	//interpolator.push_back(m_Vec3Properties[i]->GetInterpolator(m_QuatProperties[i]));
			//}
 
			//for (unsigned int i = 0; i < m_QuatProperties.size(); i++)
			//{
			//	//interpolator.push_back(m_QuatProperties[i]->GetInterpolator(m_QuatProperties[i]));
			//}
			for(unsigned int i=0;i<m_KeyValueCollectionBaseArray.size();i++)
				interpolator.push_back(m_KeyValueCollectionBaseArray[i]->GetInterpolator(m_KeyValueCollectionBaseArray[i]));
			return interpolator;
		}
	}
}
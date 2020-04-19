#pragma once
#include "controller.h"
#include "animation/animationlayer.h"
namespace sparky
{
	namespace animation
	{

		void Controller::Initialize(std::vector<AnimationLayer*>& layers)
		{
			//m_Interpolators = layer->GetInterPolator();
			/*for (unsigned int i = 0; i < layers.size(); i++)
			{
				const auto& temp = layers[i]->GetInterPolator();
				for (unsigned int j = 0; j < temp.size(); j++)
					m_InterpolatorMap.insert(std::make_pair(temp[i]->GetUniqueKey(), temp[j]));
			}*/
		}

		void Controller::UpdateProperties(unsigned long elapse)
		{
			/*for (unsigned int i = 0; i < m_FloatInterpolators.size(); i++)
			{
				m_FloatInterpolators[i]->Evaluate(elapse);
			}

			for (unsigned int i = 0;i<m_Vec3Interpolators.size();i++)
			{
				m_Vec3Interpolators[i]->Evaluate(elapse);
			}

			for (unsigned int i = 0;i<m_QuatInterpolators.size();i++)
			{
				m_QuatInterpolators[i]->Evaluate(elapse);
			}*/

	/*		for (unsigned int i = 0; i < m_Interpolators.size(); i++)
			{
				m_Interpolators[i]->Evaluate(elapse);
			}*/
		}

	}
}
#pragma once
#include "controller.h"
#include "animation/animationlayer.h"
namespace sparky
{
	namespace animation
	{

		void Controller::Initialize(AnimationLayer* layer)
		{
			m_FloatInterpolators = layer->GetFloatInterpolator();
			m_Vec3Interpolators = layer->GetVec3Interpolator();
			m_QuatInterpolators = layer->GetQuatInterpolator();
		}

		void Controller::UpdateProperties(unsigned long elapse)
		{
			for (unsigned int i = 0; i < m_FloatInterpolators.size(); i++)
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
			}
		}

	}
}
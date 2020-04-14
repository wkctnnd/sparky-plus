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

		void Controller::UpdateProperties()
		{

		}

	}
}
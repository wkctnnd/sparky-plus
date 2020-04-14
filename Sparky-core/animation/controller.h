#pragma once
#include <string>
#include <vector>
#include "maths/vec3.h"
#include "Interpolator.h"
#include "maths/quaternion.h"
using namespace sparky::maths;
namespace sparky
{
	namespace animation
	{
 
 
		class Controller
		{
		public:
			void Initialize(class AnimationLayer* layer);
			void UpdateProperties();
		private:
			std::vector<Interpolator<float>*>  m_FloatInterpolators;
			std::vector<Interpolator<vec3>*> m_Vec3Interpolators;
			std::vector<Interpolator<Quaternion>*> m_QuatInterpolators;
			float m_CurrentTime;
		};


	}
}
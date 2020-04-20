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
			void Initialize(std::vector<class AnimationLayer*>& layers);
			void Update(unsigned long elapse);

		private:
			/*std::vector<Interpolator<float>*>  m_FloatInterpolators;
			std::vector<Interpolator<vec3>*> m_Vec3Interpolators;
			std::vector<Interpolator<Quaternion>*> m_QuatInterpolators;*/

			std::vector<AnimationLayer*>  m_KeyValueCollectionArray;
			float m_CurrentTime;

			//std::map<int, InterpolatorBase*> m_InterpolatorMap;
		};


	}
}
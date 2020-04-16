#pragma once
#include <vector>
#include "property.h"
#include "maths/quaternion.h"
#include "maths/vec3.h"
using namespace sparky::maths;
namespace sparky
{
	namespace animation
	{
		class AnimationLayer
		{
		public:
			bool GetLoop() const;
			void SetLoop(bool loop);

			void SetWeight(float weight);
			bool GetWeight()const;

			//Property<float> GetFloatProperties();
			//std::vector<Interpolator<float>*> GetFloatInterpolator();
			//std::vector<Interpolator<vec3>*> GetVec3Interpolator();
			//std::vector<Interpolator<Quaternion>*> GetQuatInterpolator();

			std::vector<InterpolatorBase*> GetInterPolator();

		private:
			std::vector<Property<float>*> m_FloatProperties;
			std::vector<Property<Quaternion>*> 	m_QuatProperties;
			std::vector<Property<vec3>*> m_Vec3Properties;
			float m_BlendWeight;
			bool m_Loop;
		};



	}
}
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
 
		//通过状态机控制动画的切换
		class Controller
		{
		public:
			void Initialize(std::vector<class AnimationLayer*>& layers);
			void Update(unsigned long elapse);
			int GetAnimationStackCount() { return m_AnimationStackArray.size(); };
			class AnimationStack* GetAnimationStack(int id) { return m_AnimationStackArray[id]; }
		 
		private:
			/*std::vector<Interpolator<float>*>  m_FloatInterpolators;
			std::vector<Interpolator<vec3>*> m_Vec3Interpolators;
			std::vector<Interpolator<Quaternion>*> m_QuatInterpolators;*/

			std::vector<class AnimationStack*>  m_AnimationStackArray;
			float m_CurrentTime;

			int m_CurrentStackId;
			//std::map<int, InterpolatorBase*> m_InterpolatorMap;
		};


	}
}
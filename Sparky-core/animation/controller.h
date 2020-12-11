#pragma once
#include <string>
#include <vector>
#include "maths/vec3.h"
#include "Interpolator.h"
#include "maths/quaternion.h"

using namespace sparky::maths;
namespace sparky
{
	namespace world
	{
		class AnimationComponent;
	}
	namespace animation
	{
 
		//通过状态机控制动画的切换
		class Controller
		{
		public:
			void Initialize(std::vector<class AnimationStack*>& stacks);
			void Update(unsigned long elapse);
			int GetAnimationStackCount() { return m_AnimationStackArray.size(); };
			class AnimationStack* GetAnimationStack(int id) { return m_AnimationStackArray[id]; }
			//void AddAnimationStack() { m_AnimationStackArray.push_back(); }

			void SetOwner(world::AnimationComponent* owner)
			{
				m_Owner = owner;
			}

		protected:
			world::AnimationComponent *m_Owner;
		private:
			/*std::vector<Interpolator<float>*>  m_FloatInterpolators;
			std::vector<Interpolator<float3>*> m_float3Interpolators;
			std::vector<Interpolator<Quaternion>*> m_QuatInterpolators;*/

			std::vector<class AnimationStack*>  m_AnimationStackArray;
			float m_CurrentTime;

			int m_CurrentStackId;
			//std::map<int, InterpolatorBase*> m_InterpolatorMap;
		};


	}
}
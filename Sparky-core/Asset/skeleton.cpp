#pragma once
#include "Asset/skeleton.h"
#include "engine.h"
#include "maths/mat4.h"
using namespace sparky::maths;
using namespace sparky::animation;
namespace sparky
{
	namespace asset
	{
		void Skeleton::UpdateWorldMatrix()
		{
			long elapse = Engine::GlobalTimer.GetElapsemillionseconds();
			UpdateJoint(elapse, joints[0]);

		}

		void Skeleton::UpdateJoint(unsigned long elapes, joint *j)
		{
			
			vec3 translate = j->m_Translation.EvaluateValue(elapes);
			vec3 scale = j->m_Scale.EvaluateValue(elapes);
			Quaternion quat = j->m_Quat.EvaluateValue(elapes);

			mat4 TranslateMat = mat4::Translate(translate);
			mat RotateMat = mat4::rotation(quat);

			for (int i = 0; i < j->children.size(); i++)
			{
				UpdateJoint(elapes, j->children[i]);


			}
		}
	
	}
}
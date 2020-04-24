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
			
			vec3 translate(0,0,0);
			vec3 scale(1, 1, 1);
			Quaternion quat(1, 0, 0, 0);
			j->m_Translation.EvaluateValue(elapes, translate);
			j->m_Scale.EvaluateValue(elapes, scale);
			j->m_Quat.EvaluateValue(elapes, quat);

			mat4 TranslateMat = mat4::Translate(translate);
			mat4 RotateMat = mat4::rotation(quat);
			mat4 ScaleMat = mat4::scale(scale);
			
			WorldPose[j->m_Id] = TranslateMat * RotateMat * ScaleMat;

			for (int i = 0; i < j->children.size(); i++)
			{
				UpdateJoint(elapes, j->children[i]);


			}
		}
	
	}
}
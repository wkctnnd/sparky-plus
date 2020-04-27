#pragma once
#include <vector>
#include "maths/vec3.h"
#include "maths/mat4.h"
#include "maths/quaternion.h"
#include "animation/property.h"

using namespace sparky::maths;
using namespace sparky::animation;
namespace sparky
{
	namespace asset
	{
		struct joint
		{
			joint(joint* p, std::string n):m_Translation(Translate_Property_Type, n),m_Scale(Scale_Property_Type, n), m_Quat(Rotation_Property_Type, n)
			{
				bonename = n;
				parent = p;

			}
			
			int m_Id;
			std::string bonename;
			//wostd::string 
			//vec3 position;
			mat4 InvBoneMatrix;

			Property<vec3> m_Translation;
			Property<vec3> m_Scale;
			Property<Quaternion> m_Quat;
			
			joint* parent;
			std::vector<joint*> children;
		};
		struct Skeleton
		{
			void UpdateWorldMatrix();
			std::vector<joint*> joints;
			std::vector<mat4> WorldPose;
			std::vector<mat4> SkinMat;

		private:
			void UpdateJoint(unsigned long elapse, joint* j);
			void UpdateSkinMat();
		};
	}
}
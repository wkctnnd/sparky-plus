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
			joint(joint* p, std::string n):m_Translation(Translate_Property_Type, "Translate"),m_Scale(Scale_Property_Type, "Scale"), m_Quat(Rotation_Property_Type, "Rotate")
			{
				bonename = n;
				parent = p;

			}
			
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
			std::vector<joint*> joints;
		};
	}
}
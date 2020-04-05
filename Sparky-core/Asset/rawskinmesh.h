#pragma once

#include <vector>
#include "maths/vec3.h"
#include "maths/vec2.h"
#include "maths/vec4.h"
#include <string>
using namespace sparky::maths;
namespace sparky
{
	namespace asset
	{
		struct joint
		{
			joint(joint* p, std::string n)
			{
				name = n;
				parent = p;

			}
			std::string name;
			vec3 position;
			joint* parent;
			std::vector<joint*> children;
		};
		struct Skeleton
		{
			std::vector<joint*> joints;
		};

		struct RawSkinMesh
		{
			std::vector<vec3> m_Position;
			std::vector<vec4> m_Color;
			std::vector<vec3> m_Tangent;
			std::vector<vec3> m_Normal;
			std::vector<vec4> m_Weight;
			std::vector<vec4> m_BoneIndex;
			std::vector<unsigned short> m_Faces;
			Skeleton m_Skeleton;
		};
	}
}

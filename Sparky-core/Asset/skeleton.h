#pragma once
#include <vector>
#include "maths/vec3.h"
#include "maths/mat4.h"
using namespace sparky::maths;
namespace sparky
{
	namespace asset
	{
		struct joint
		{
			joint(joint* p, std::string n)
			{
				bonename = n;
				parent = p;

			}
			
			std::string bonename;
			//wostd::string 
			//vec3 position;
			mat4 InvBoneMatrix;

			
			joint* parent;
			std::vector<joint*> children;
		};
		struct Skeleton
		{
			std::vector<joint*> joints;
		};
	}
}
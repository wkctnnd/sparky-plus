#pragma once
#include <vector>
#include "maths/vec3.h"
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
	}
}
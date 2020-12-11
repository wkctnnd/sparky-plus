#pragma once
#include "maths/AABox.h"
#include "physics/pxShape.h"
using namespace sparky::maths;
 
namespace sparky
{
	namespace phyx
	{
		bool IsIntersectAABBWithAABB(AABox& box0, AABox& box1, HitResult& result);

	}
}

#pragma once
#include "maths/AABox.h"
#include "physics/pxShape.h"
#include "maths/sphere.h"
using namespace sparky::maths;
 
namespace sparky
{
	namespace phyx
	{
		bool IsIntersectAABBWithAABB(AABox& box0, AABox& box1, HitResult& result);
		bool IsIntersectSphereWithSphere(Shpere& sphere0, Shpere& Shpere1, HitResult& result);
		bool IsIntersectSphereWithAABB(Shpere& sphere0, AABox& box1, HitResult& result);
	}
}

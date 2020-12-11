#include "CollisionHelper.h"
namespace sparky
{
	namespace phyx
	{
		bool IsIntersectAABBWithAABB(AABox& box0, AABox& box1, HitResult& result)
		{
			float3 maxA = box0.m_Center - box0.m_Extension / 2;
			float3 minA = box0.m_Center + box0.m_Extension / 2;

			float3 maxB = box1.m_Center - box1.m_Extension / 2;
			float3 minB = box1.m_Center + box1.m_Extension / 2;
			if (maxB.x < minA.x || maxA.x < minB.x)
			{
				return false;
			}
			if (maxB.y < minA.y || maxA.y < minB.y)
			{
				return false;
			}
			if (maxB.z < minA.z || maxA.z < minB.z)
			{
				return false;
			}


			return true;
		}
	}
}
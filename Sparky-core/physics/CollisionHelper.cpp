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

		bool IsIntersectSphereWithSphere(Shpere& sphere0, Shpere& Shpere1, HitResult& result)
		{
			float3 disvec = (sphere0.m_Center - Shpere1.m_Center);
			float dis = disvec.length();
			 if (dis<sphere0.m_Radius+ Shpere1.m_Radius)
			 {
				 return true;
			 }
		
			 return false;
 
		}


		bool IsIntersectSphereWithAABB(Shpere& sphere0, AABox& box1, HitResult& result)
		{
			float3 desvec = sphere0.m_Center - box1.m_Center;
			if (abs(desvec.x)>sphere0.m_Radius+box1.m_Extension.x)
			{
				return false;
			}
			if (abs(desvec.y) > sphere0.m_Radius + box1.m_Extension.y)
			{
				return false;
			}

			if (abs(desvec.z) > sphere0.m_Radius + box1.m_Extension.z)
			{
				return false;
			}

			return true;
		}
	}
}
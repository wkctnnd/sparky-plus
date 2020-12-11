#pragma once

#include "PxAABBShape.h"
 #include "maths/AABox.h"
#include "pxShape.h"
#include "Asset/rawmesh.h"
#include "CollisionHelper.h"

using namespace sparky::asset;


namespace sparky
{

	namespace phyx
	{
 
		bool PxAABBShape::Collide(PxShape* othershape, HitResult& result)
		{
			if (othershape->GetType() == AABB_Shape)
			{
				return IsIntersectAABBWithAABB(m_BoundBox, ((PxAABBShape*)(othershape))->m_BoundBox, result);	
			}
		}

		PxAABBShape::PxAABBShape(asset::RawMesh * mesh)
		{
			m_ShapeType = AABB_Shape;
			float3 max(-100000, -100000, -100000);
			float3 min(100000, 100000, 100000);
			for (int i = 0; i < mesh->m_Position.size(); i++)
			{
				if (max.x < mesh->m_Position[i].x)
				{
					max.x = mesh->m_Position[i].x;
				}
				if (max.y < mesh->m_Position[i].y)
				{
					max.y = mesh->m_Position[i].y;
				}

				if (max.z < mesh->m_Position[i].z)
				{
					max.z = mesh->m_Position[i].z;
				}


				if (min.x > mesh->m_Position[i].x)
				{
					min.x = mesh->m_Position[i].x;
				}
				if (min.y > mesh->m_Position[i].y)
				{
					min.y = mesh->m_Position[i].y;
				}

				if (min.z > mesh->m_Position[i].z)
				{
					min.z = mesh->m_Position[i].z;
				}
			}

			m_BoundBox.m_Center = (max + min) / 2;
			m_BoundBox.m_Extension = (max - min);
		}

		//PxAABBShape::PxAABBShape(RawMesh* mesh)
	


	}
}
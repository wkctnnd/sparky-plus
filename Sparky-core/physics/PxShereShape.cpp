#include "physics/PxShpereShape.h"
#include "physics/PxAABBShape.h"
#include "maths/vec3.h"
#include <vector>
#include "maths/AABox.h"
#include "CollisionHelper.h"
using namespace sparky::maths;
namespace sparky
{
	namespace phyx
	{


		bool PxShpereShape::Collide(PxShape* othershape, HitResult& result)
		{
			if (othershape->GetType() == Sphere_Shape)
			{
				return IsIntersectSphereWithSphere(m_Sphere, ((PxShpereShape*)(othershape))->m_Sphere, result);
			}
			else if (othershape->GetType()==AABB_Shape)
			{
				return IsIntersectSphereWithAABB(m_Sphere, ((PxAABBShape*)(othershape))->m_BoundBox, result);
			}
		}
		PxShpereShape::PxShpereShape(asset::RawMesh* mesh)
		{
			m_ShapeType = Sphere_Shape;
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

			m_Sphere.m_Center = (max + min) / 2;
			m_Sphere.m_Radius = 0;
			for (int i = 0; i < mesh->m_Position.size(); i++)
			{
				float3 vec = mesh->m_Position[i] - m_Sphere.m_Center;
				if (vec.length()> m_Sphere.m_Radius)
				{
					m_Sphere.m_Radius = vec.length();
				}
				 
			}
		}
 

		 
	};
}

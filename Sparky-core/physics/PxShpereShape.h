#pragma once

#include "maths/vec3.h"
#include <vector>
#include "maths/sphere.h"
#include "pxShape.h"
#include "Asset/rawmesh.h"

using namespace sparky::maths;
namespace sparky
{
	namespace asset
	{
		class RawMesh;
	}
	namespace phyx
	{
		class PxAABBShape;
		class PxShpereShape :public PxShape
		{
			friend PxAABBShape;
		public:
			virtual bool Collide(PxShape* othershape, HitResult& result);
			PxShpereShape(asset::RawMesh* mesh);
			PxShpereShape(PxShpereShape* shape, mat4& mat)
			{
				m_ShapeType = ShapeType::Sphere_Shape;
				m_Sphere = shape->m_Sphere;
				m_Sphere.Transform(mat);
			}

			PxShape* NewShapeFromMatrix(maths::mat4& mat)
			{
	 
				PxShpereShape* shape = new PxShpereShape(this, mat);
				return shape;
				 
			}
		protected:

			 sparky::maths::Shpere m_Sphere;
			//void *UpdateDelegate(int);
		};



	}
}
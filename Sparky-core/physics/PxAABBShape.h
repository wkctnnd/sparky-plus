#pragma once

#include "maths/vec3.h"
#include <vector>
#include "maths/AABox.h"
#include "pxShape.h"
#include "Asset/rawmesh.h"
#include "maths/mat4.h"
namespace sparky
{
	namespace asset
	{
		class RawMesh;
	}
	namespace phyx
	{
		class PxShpereShape;
		class PxAABBShape:public PxShape
		{
			friend PxShpereShape;
		public:
			virtual bool Collide(PxShape* othershape, HitResult& result);
			PxShape* NewShapeFromMatrix(maths::mat4& mat);
			PxAABBShape(asset::RawMesh* mesh);
			PxAABBShape(PxAABBShape* shape, mat4& mat)
			{
				m_BoundBox = shape->m_BoundBox;
				m_BoundBox.Transform(mat);
			}
 
		protected:

			AABox m_BoundBox;
			//void *UpdateDelegate(int);
		};


	
	}
}
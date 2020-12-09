#pragma once

#include "maths/vec3.h"
#include <vector>
#include "maths/AABox.h"
#include "pxShape.h"

namespace sparky
{
	namespace phyx
	{
 
		class PxAABBShape:public PxShape
		{
		public:
			virtual bool Collide(PxShape* othershape, HitResult& result);
			PxAABBShape(RawMesh* mesh);
		protected:

			AABox m_BoundBox;
			//void *UpdateDelegate(int);
		};


	
	}
}
#pragma once

#include "maths/vec3.h"
#include <vector>
#include "maths/AABox.h"
#include "pxShape.h"

namespace sparky
{
	namespace phyx
	{
		enum ShapeType
		{
			Shere_Shape,
			AABB_Shape,
			OBB_Shadpe,
		};
		class PxShape
		{
		public:
 

		protected:

			AABox m_BoundBox;
			//void *UpdateDelegate(int);
		};
	}
}
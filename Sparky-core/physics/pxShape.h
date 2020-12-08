#pragma once
 
#include "maths/vec3.h"
#include <vector>
#include "maths/AABox.h"
#include "PxObject.h"

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
			 
			ShapeType GetType() { return m_ShapeType; }


 
		protected:

			ShapeType m_ShapeType;
			 

			//void *UpdateDelegate(int);
		};
	}
}
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


		class HitResult
		{

		};


		class PxShape  
		{
		public:
			 
			ShapeType GetType() { return m_ShapeType; }

			virtual bool Collide(PxShape* shape, HitResult& result) = 0;
 
		protected:

			ShapeType m_ShapeType;
			 

			//void *UpdateDelegate(int);
		};
	}
}
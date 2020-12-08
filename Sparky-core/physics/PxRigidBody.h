#pragma once
#pragma once
#include "maths/vec3.h"
#include <vector>
#include "maths/AABox.h"
#include "PxObject.h"
 
namespace sparky
{
	namespace phyx
	{
		class PxRigidBody :public PxObject
		{
		public:
			PxRigidBody(world::ScriptComponent* sc):PxObject(sc) {   }
			PxObjectType GetType() { return SOFT_BODY; }
			 

 
		private:
		 
			
			//AABox m_BoundBox;

			//void *UpdateDelegate(int);
		};
	}
}
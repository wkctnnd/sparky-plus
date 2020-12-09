#pragma once
#pragma once
#include "maths/vec3.h"
#include <vector>
#include "maths/AABox.h"
#include "PxObject.h"
#include "pxShape.h"
namespace sparky
{
	namespace asset
	{
		class RawMesh;
	}
	namespace phyx
	{
		
		class PxRigidBody :public PxObject
		{
		public:
			PxRigidBody(world::ScriptComponent* sc):PxObject(sc) {   }
			PxObjectType GetType() { return SOFT_BODY; }
			 
			void GenerateShape(class RawMesh* mesh);
 
		private:
		 
			class PxShape *m_Shape;
			phyx::ShapeType m_ShapeType;
			//AABox m_BoundBox;

			//void *UpdateDelegate(int);
		};
	}
}
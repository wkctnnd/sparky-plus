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
			PxRigidBody(world::ScriptComponent* sc);
			PxObjectType GetType();
			void SetShapeType(phyx::ShapeType type)
			{
				m_ShapeType = type;
			 }
			void GenerateShape(asset::RawMesh* mesh);

 
		private:
		 
			class phyx::PxShape *m_Shape;
			phyx::ShapeType m_ShapeType;
			//AABox m_BoundBox;

			//void *UpdateDelegate(int);
		};
	}
}
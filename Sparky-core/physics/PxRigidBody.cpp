#pragma once
#include "PxRigidBody.h"
#include "PxAABBShape.h"
namespace sparky
{
	namespace phyx
	{

		PxRigidBody::PxRigidBody(world::ScriptComponent* sc) :PxObject(sc) {   }
		PxObjectType PxRigidBody::GetType() { return SOFT_BODY; }

		void PxRigidBody::GenerateShape(RawMesh* mesh)
		{
			switch (m_ShapeType)
			{
			case sparky::phyx::Shere_Shape:
				m_Shape = new PxAABBShape();
				break;
			case sparky::phyx::AABB_Shape:
				m_Shape = new PxAABBShape();
				break;
			case sparky::phyx::OBB_Shadpe:
				m_Shape = new PxAABBShape();
				break;
			default:
				break;
			}
		}


	};
}

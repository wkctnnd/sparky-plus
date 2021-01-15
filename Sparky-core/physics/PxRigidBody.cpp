#pragma once
#include "PxRigidBody.h"
#include "PxAABBShape.h"
#include "PxShpereShape.h"
namespace sparky
{
	namespace phyx
	{
		PxRigidBody::PxRigidBody(world::Actor* sc, phyx::PxShape* shape, mat4* matp) :PxObject(sc, shape, matp) { m_ShapeType = shape->GetType(); }
		PxObjectType PxRigidBody::GetType() { return RIGID_BODY; }

		void PxRigidBody::GenerateShape(asset::RawMesh* mesh)
		{
			switch (m_ShapeType)
			{
			case sparky::phyx::Sphere_Shape:
				m_Shape = new PxShpereShape(mesh);
				break;
			case sparky::phyx::AABB_Shape:
				m_Shape = new PxAABBShape(mesh);
				break;
			case sparky::phyx::OBB_Shadpe:
				m_Shape = new PxAABBShape(mesh);
				break;
			default:
				break;
			}
		}


	};
}

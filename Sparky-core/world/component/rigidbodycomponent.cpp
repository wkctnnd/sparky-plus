#pragma once
#include "rigidbodycomponent.h"
#include "graphics/rendertarget.h"
#include "world/actor.h"
#include "transformcomponent.h"
#include "graphics/texture/rendertexture.h"
#include "graphics/rendertarget.h"
#include "render/View.h"
#include "physics/PxRigidBody.h"
#include "physics/PxAABBShape.h"
#include "physics/pxShape.h"
#include "physics/PxShpereShape.h"
using namespace sparky::graphics;
using namespace sparky::render;
using namespace sparky::phyx;
namespace sparky
{
	namespace world
	{
		ComponentType RigidBodyComponent::TYPE = ComponentType::RIGIDBODY_TYPE;

//#ifdef EDITOR_USE
//		void RigidBodyComponent::GenerateShape()
//		{
//			if (m_Type == AABB_Shape)
//			{
//				AABox box;
//
//			}
//		}
//#endif

		phyx::PxRigidBody * RigidBodyComponent::GetRigidBody()
		{
			if (m_Owner->IsActive()&&m_Shape)
			{
				ScriptComponent* comp = (ScriptComponent*)m_Owner->GetComponent<ScriptComponent>();
				PxRigidBody* body = new PxRigidBody(comp,m_Shape, &m_Owner->GetTransform()->GetWorldTransform());
				 
				//body->SetWorldMatrix(m_Owner->GetTransform()->GetWorldTransform());
				return body;
			}

			return 0;
		}

		void RigidBodyComponent::GenerateShape(class asset::RawMesh* mesh, phyx::ShapeType type)
		{
	/*		m_RigidBody = new  PxRigidBody(component);
			m_RigidBody->SetShapeType(type);
			m_RigidBody->GenerateShape(mesh);*/
			switch (type)
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
	}
}

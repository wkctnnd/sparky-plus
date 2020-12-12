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

		void RigidBodyComponent::GenerateShape(class asset::RawMesh* mesh, class world::ScriptComponent* component, phyx::ShapeType type)
		{
			m_RigidBody = new  PxRigidBody(component);
			m_RigidBody->SetShapeType(type);
			m_RigidBody->GenerateShape(mesh);
		}
	}
}

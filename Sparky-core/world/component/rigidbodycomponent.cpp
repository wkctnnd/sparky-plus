#pragma once
#include "rigidbodycomponent.h"
#include "graphics/rendertarget.h"
#include "world/actor.h"
#include "transformcomponent.h"
#include "graphics/texture/rendertexture.h"
#include "graphics/rendertarget.h"
#include "render/View.h"

#include "physics/PxAABBShape.h"
using namespace sparky::graphics;
using namespace sparky::render;
using namespace sparky::phyx;
namespace sparky
{
	namespace world
	{
		ComponentType RigidBodyComponent::TYPE = ComponentType::CAMER_TYPE;

#ifdef EDITOR_USE
		void RigidBodyComponent::GenerateShape()
		{
			if (m_Type == AABB_Shape)
			{
				AABox box;

			}
		}
#endif
	}
}

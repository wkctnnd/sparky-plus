#pragma once
#include "staticmeshrenderercomponent.h"
#include "render/mesh.h"
using namespace sparky::maths;
namespace sparky
{
	namespace world
	{
		ComponentType StaticMeshRendererComponent::TYPE = ComponentType::TRANSFORM_TYPE;
		
		void StaticMeshRendererComponent::PostUpdate()
		{

		}

		void StaticMeshRendererComponent::AddStaticMesh(RawMesh* mesh)
		{

		}

		Renderable* StaticMeshRendererComponent::GetRenderable()
		{
			 
			Mesh* m = Mesh::Load(*(m_Trunks[0].staticmesh));
			return m;
		}
	}
}


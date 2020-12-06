#pragma once
#include "staticmeshrenderercomponent.h"
#include "render/mesh.h"
#include "world/actor.h"
#include "../PrimitiveSceneProxy.h"
using namespace sparky::maths;
namespace sparky
{
	namespace world
	{
		ComponentType StaticMeshRendererComponent::TYPE = ComponentType::STATICMESHRENDERER_TYPE;
		
		void StaticMeshRendererComponent::PostUpdate()
		{

		}

		void StaticMeshRendererComponent::AddStaticMesh(RawMesh* mesh)
		{
			m_RenderMesh = render::Mesh::Load(*mesh);
		}

		StaticMeshRendererComponent::StaticMeshRendererComponent(Actor* owner) :Component(owner)
		{

		}

		Renderable* StaticMeshRendererComponent::GetRenderable()
		{
			return m_RenderMesh;
			/*Mesh* m = Mesh::Load(*(m_Trunks[0].staticmesh));
			return m;*/
		}

		SceneProxy* StaticMeshRendererComponent::GetSceneProxy()
		{
			mat4 worldmat = m_Owner->GetTransform()->GetWorldTransform();
			PrimitiveSceneProxy* proxy = new PrimitiveSceneProxy(m_RenderMesh, worldmat);
			return proxy;
		}
	}
}


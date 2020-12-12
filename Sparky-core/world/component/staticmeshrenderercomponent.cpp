#pragma once
#include "staticmeshrenderercomponent.h"
#include "render/mesh.h"
#include "world/actor.h"
#include "../PrimitiveSceneProxy.h"
#include "render/rendermaterial.h"
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

		void StaticMeshRendererComponent::AddMaterial( Material* mat)
		{
			RenderMaterial* rmat = RenderMaterial::CreateMaterial(mat);
			m_Materials.push_back(rmat);
				

		}

		RenderMaterial* StaticMeshRendererComponent::GetMaterial(int index)
		{
			if (m_Materials.empty())
				return m_DefaultMaterial;
			return m_Materials[index];
		}
		StaticMeshRendererComponent::StaticMeshRendererComponent(Actor* owner) :Component(owner)
		{
			m_DefaultMaterial = RenderMaterial::CreateDefaultMaterial();
		}

		Renderable* StaticMeshRendererComponent::GetRenderable()
		{
			return m_RenderMesh;
			/*Mesh* m = Mesh::Load(*(m_Trunks[0].staticmesh));
			return m;*/
		}


		// 默认只有一个材质
		SceneProxy* StaticMeshRendererComponent::GetSceneProxy()
		{
			if (m_Owner->IsActive())
			{
				mat4 worldmat = m_Owner->GetTransform()->GetWorldTransform();
				RenderMaterial* mat;
				if (!m_Materials.empty())
				{
					mat = m_Materials[0];
				}
				else
					mat = m_DefaultMaterial;
				PrimitiveSceneProxy* proxy = new PrimitiveSceneProxy(m_RenderMesh, mat, worldmat);
				return proxy;
			}
			return 0;
		}
	}
}


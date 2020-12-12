#include "gamerenderer.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/scene.h"
#include "world/actor.h"
#include "world/PrimitiveSceneProxy.h"
#include "render/rendermaterial.h"
using namespace sparky::world;
namespace sparky
{
	namespace render
	{
		void  GameRenderer::AddRenderable(Renderable* r)
		{

		}

		void GameRenderer::PostUpdate()
		{
			PhotoObjects.clear();
			m_PrimitiveSceneProxy.clear();
			std::vector<StaticMeshRendererComponent*> comps = m_Scene->GetRoot()->GetChildrenComponents<StaticMeshRendererComponent>();
			/*for (int i = 0; i < comps.size(); i++)
			{
				Renderable* r = comps[i]->GetRenderable();
				PhotoObjects.push_back(r);
			}*/

			for (int i = 0; i < comps.size(); i++)
			{
				PrimitiveSceneProxy* r = (PrimitiveSceneProxy*)comps[i]->GetSceneProxy();
				if (r)
				{
					m_PrimitiveSceneProxy.push_back(r);
				}
				
			}

		}

		GameRenderer::GameRenderer(world::Scene* scene)
		{
			m_Scene = scene;
		}
		void GameRenderer::Initialize()
		{
			m_SimpleShader = new GraphicsShader("shaders/texturelight.vert", "shaders/texturelight.frag");
			m_ToonShader = new GraphicsShader("shaders/toon.vert", "shaders/toon.frag");
			 
		}


		void GameRenderer::RenderScene(float3 position, float3 axis, float angle)
		{


			glEnable(GL_DEPTH_TEST);

			glDepthFunc(GL_LESS);
			glClearColor(0, 0, 0, 1);
			glClearDepth(1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


			glm::mat4 trans = glm::mat4(1.0f);
			trans = glm::rotate(trans, angle, glm::vec3(axis.x, axis.y, axis.z));
			glm::vec3 up = trans * glm::vec4(0, 1, 0, 0);

			glm::mat4 mViewMatrix = glm::lookAt(glm::vec3(position.x, position.y, position.z), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
			glm::mat4 mProjectionMatrix = glm::perspective(90.0, 1.0, 0.1, 1000.0);


			m_ToonShader->enable();

			m_ToonShader->setUniformMat41("pr_matrix", mProjectionMatrix);
			m_ToonShader->setUniformMat41("view_matrix", mViewMatrix);
			//m_TestShader->setUniformMat41("world_matrix", mViewMatrix);
			m_ToonShader->setUniform3f("camerapos", position);

			for (int i = 0; i < m_PrimitiveSceneProxy.size(); i++)
			{
				if (m_PrimitiveSceneProxy[i]->GetMaterial()->IsToon())
				{
					mat4 worldmat = m_PrimitiveSceneProxy[i]->GetWorldMatrix();
				 
					m_ToonShader->setUniformMat4("world_matrix", worldmat);
					m_ToonShader->setUniform3f("DiffuseColor", m_PrimitiveSceneProxy[i]->GetMaterial()->GetDiffuseColor());
					Renderable* rb = m_PrimitiveSceneProxy[i]->getRenderable();
					rb->render();
				}

			}
			m_ToonShader->disable();


			m_SimpleShader->enable();

			m_SimpleShader->setUniformMat41("pr_matrix", mProjectionMatrix);
			m_SimpleShader->setUniformMat41("view_matrix", mViewMatrix);
			//m_TestShader->setUniformMat41("world_matrix", mViewMatrix);
			m_SimpleShader->setUniform3f("campos", float3(40, 60, 40));
			
			for (int i = 0; i < m_PrimitiveSceneProxy.size(); i++)
			{
				if (!m_PrimitiveSceneProxy[i]->GetMaterial()->IsToon())
				{
					mat4 worldmat = m_PrimitiveSceneProxy[i]->GetWorldMatrix();
					m_SimpleShader->setUniformMat4("world_matrix", worldmat);
					m_SimpleShader->SetTexture("tex", m_PrimitiveSceneProxy[i]->GetMaterial()->GetDiffuseMap());
					Renderable* rb = m_PrimitiveSceneProxy[i]->getRenderable();
					rb->render();
				}

			}
			m_SimpleShader->disable();


		}
	
	}
}
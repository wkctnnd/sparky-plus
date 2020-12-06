#include "photorenderer.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/scene.h"
#include "world/actor.h"
#include "world/PrimitiveSceneProxy.h"
using namespace sparky::world;
namespace sparky
{
	namespace render
	{
		void  PhotoRenderer::AddRenderable(Renderable* r)
		{

		}

		void PhotoRenderer::PostUpdate()
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
				m_PrimitiveSceneProxy.push_back(r);
			}

		}

		PhotoRenderer::PhotoRenderer(world::Scene* scene)
		{
			m_Scene = scene;
		}
		void PhotoRenderer::Initialize()
		{
			m_PhotoShader = new GraphicsShader("shaders/ocean.vert", "shaders/ocean.frag");
			m_DepthShader = new GraphicsShader("shaders/depth.vert", "shaders/depth.frag");
			m_TestShader = new GraphicsShader("shaders/test.vert", "shaders/test.frag");
		}


		void PhotoRenderer::RenderSceneTest()
		{


			glEnable(GL_DEPTH_TEST);

			glDepthFunc(GL_LESS);
			glClearColor(0, 0, 0, 1);
			glClearDepth(1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			m_TestShader->enable();



			glm::mat4 mViewMatrix = glm::lookAt(glm::vec3(0, 0.25f, -80.0f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
			glm::mat4 mProjectionMatrix = glm::perspective(90.0, 1.0, 0.1, 1000.0);






			m_TestShader->setUniformMat41("pr_matrix", mProjectionMatrix);
			m_TestShader->setUniformMat41("view_matrix", mViewMatrix);
			//m_TestShader->setUniformMat41("world_matrix", mViewMatrix);
			m_TestShader->setUniform3f("campos", float3(40, 60, 40));
			//m_OceanShader->setUniform3f("lightdir", )

		/*	for (int i = 0;i<PhotoObjects.size();i++)
			{
				PhotoObjects[i]->render();
			}*/

			for (int i = 0; i < m_PrimitiveSceneProxy.size(); i++)
			{
				mat4 worldmat = m_PrimitiveSceneProxy[i]->GetWorldMatrix();
				m_TestShader->setUniformMat4("world_matrix", worldmat);
				Renderable* rb = m_PrimitiveSceneProxy[i]->getRenderable();
				rb->render();
			}


		}
		void PhotoRenderer::RenderScene()
		{


			glEnable(GL_DEPTH_TEST);

			glDepthFunc(GL_LESS);
			glClearColor(0, 0, 0, 1);
			glClearDepth(1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			m_PhotoShader->enable();



			glm::mat4 mViewMatrix = glm::lookAt(glm::vec3(0, 0.25f, -80.0f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
			glm::mat4 mProjectionMatrix = glm::perspective(90.0, 1.0, 0.1, 1000.0);






			m_PhotoShader->setUniformMat41("pr_matrix", mProjectionMatrix);
			m_PhotoShader->setUniformMat41("vw_matrix", mViewMatrix);
			m_PhotoShader->setUniform3f("campos", float3(40, 60, 40));
			//m_OceanShader->setUniform3f("lightdir", )

		/*	for (int i = 0;i<PhotoObjects.size();i++)
			{
				PhotoObjects[i]->render();
			}*/

			for (int i = 0; i < m_PrimitiveSceneProxy.size(); i++)
			{
				mat4 worldmat = m_PrimitiveSceneProxy[i]->GetWorldMatrix();
				m_PhotoShader->setUniformMat4("w_matrix", worldmat);
				Renderable* rb = m_PrimitiveSceneProxy[i]->getRenderable();
				rb->render();
			}


		}

		void PhotoRenderer::RenderSceneDepth()
		{


			glEnable(GL_DEPTH_TEST);

			glDepthFunc(GL_EQUAL);
			//glClearColor(0, 0, 0, 1);
			//glClearDepth(1);
			//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			m_DepthShader->enable();



			glm::mat4 mViewMatrix = glm::lookAt(glm::vec3(0, 0.25f, -80.0f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
			glm::mat4 mProjectionMatrix = glm::perspective(90.0, 1.0, 0.1, 1000.0);






			m_DepthShader->setUniformMat41("pr_matrix", mProjectionMatrix);
			m_DepthShader->setUniformMat41("vw_matrix", mViewMatrix);
			m_DepthShader->setUniform3f("campos", float3(40, 60, 40));
			//m_OceanShader->setUniform3f("lightdir", )

			for (int i = 0; i < PhotoObjects.size(); i++)
			{
				PhotoObjects[i]->render();
			}
			m_DepthShader->disable();
		}
	}
}
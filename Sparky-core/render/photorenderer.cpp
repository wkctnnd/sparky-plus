#include "photorenderer.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/scene.h"
#include "world/actor.h"
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
			std::vector<StaticMeshRendererComponent*> comps = m_Scene->GetRoot()->GetChildrenComponents<StaticMeshRendererComponent>();
			for (int i = 0; i < comps.size(); i++)
			{
				Renderable* r = comps[i]->GetRenderable();
				PhotoObjects.push_back(r);
			}
		}

		PhotoRenderer::PhotoRenderer(world::Scene* scene)
		{
			m_Scene = scene;
		}
		void PhotoRenderer::Initialize()
		{
			m_PhotoShader = new GraphicsShader("shaders/ocean.vert", "shaders/ocean.frag");

		 
		}


		void PhotoRenderer::RenderScene()
		{
	

			glEnable(GL_DEPTH_TEST);


			glClearColor(0, 0, 0, 1);
			glClearDepth(1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			m_PhotoShader->enable();



			glm::mat4 mViewMatrix = glm::lookAt(glm::vec3(0, 0.25f, -20.0f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
			glm::mat4 mProjectionMatrix = glm::perspective(90.0, 1.0, 0.1, 1000.0);
		





			m_PhotoShader->setUniformMat41("pr_matrix", mProjectionMatrix);
			m_PhotoShader->setUniformMat41("vw_matrix", mViewMatrix);
			m_PhotoShader->setUniform3f("campos", float3(40, 60, 40));
			//m_OceanShader->setUniform3f("lightdir", )
			
			for (int i = 0;i<PhotoObjects.size();i++)
			{
				PhotoObjects[i]->render();
			}
			m_PhotoShader->disable();
		}
	}
}
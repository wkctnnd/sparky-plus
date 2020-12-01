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
			std::vector<StaticMeshRendererComponent*> comps = m_Scene->GetRoot()->GetChildrenComponents<StaticMeshRendererComponent>();
			for (int i = 0; i < comps.size(); i++)
			{
				Renderable* r = comps[i]->GetRenderable();
				PhotoObjects.push_back(r);
			}
		}

		void PhotoRenderer::Initialize()
		{
			m_PhotoShader = new GraphicsShader("shaders/ocean.vert", "shaders/ocean.frag");

		 
		}


		void PhotoRenderer::RenderScene()
		{
			glEnable(GL_BLEND);
			/*glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT_FACE);*/
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			/*glDisable(GL_CULL_FACE);*/
			//glEnable(GL_DEPTH_TEST);
			m_PhotoShader->enable();



			glm::mat4 mViewMatrix = glm::lookAt(glm::vec3(40, 60.0f, 40), glm::vec3(128, 0, 128), glm::vec3(0, 1, 0));
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
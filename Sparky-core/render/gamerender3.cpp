#include "GameRender3.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/scene.h"
#include "world/actor.h"
#include "world/PrimitiveSceneProxy.h"
#include "render/rendermaterial.h"
#include "graphics/rendertarget.h"
#include "graphics/texture/rendertexture.h"
#include "graphics/texture/rendertexture2d.h"
using namespace sparky::graphics;
using namespace sparky::world;
namespace sparky
{
	namespace render
	{
		void  GameRenderer3::AddRenderable(Renderable* r)
		{

		}

		void GameRenderer3::PostUpdate()
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

		GameRenderer3::GameRenderer3(world::Scene* scene)
		{
			m_Scene = scene;
		}
		void GameRenderer3::Initialize()
		{
			m_SimpleShader = new GraphicsShader("shaders/basepass.vert", "shaders/basepass.frag");
			m_DepthShader = new GraphicsShader("shaders/depth.vert", "shaders/depth.frag");
			m_DepthTarget = new graphics::RenderTargetInfo();
			ColorRenderTarget  crt;
			crt.texture = new RenderTexture2D(4096, 4096, graphics::Format::RGBA);
			crt.action = Clear_Store;


			DepthStencilRenderTarget dsrt;
			dsrt.action = DepthStencilRenderTargetAction::DepthClearDontStore_StecilClearDontStore;
			dsrt.texture = new RenderTexture2D(4096, 4096, graphics::Format::DEPTH24STENCILl8);

			m_DepthTarget->SetColorRenderTarget(0, &crt);


			m_DepthTarget->SetDepthRenderTarget(&dsrt);



			//////////////////////////////////////////////////////////////////////////
			m_DepthTarget2 = new graphics::RenderTargetInfo();
			ColorRenderTarget  crt2;
			crt2.texture = new RenderTexture2D(800, 800, graphics::Format::RGBA);
			crt2.action = Clear_Store;
			DepthStencilRenderTarget dsrt2;
			dsrt2.action = DepthStencilRenderTargetAction::DepthClearDontStore_StecilClearDontStore;
			dsrt2.texture = new RenderTexture2D(800, 800, graphics::Format::DEPTH24STENCILl8);
			m_DepthTarget2->SetColorRenderTarget(0, &crt2);
			m_DepthTarget2->SetDepthRenderTarget(&dsrt2);
		}


		void GameRenderer3::RenderSceneDepth()
		{
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);
			glClearColor(1, 1, 1, 1);
			glClearDepth(1);


			m_DepthTarget->Bind();
			m_DepthShader->enable();


			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


			glViewport(0, 0, 4096, 4096);
			glm::mat4 ShadowProjectionMatrix = glm::ortho(-150.0f, 150.0f, -150.0f, 150.0f, 0.5f, 200.0f);

			/*		glm::mat4 trans2 = glm::mat4(1.0f);
			trans2 = glm::rotate(trans2, angle, glm::vec3(axis.x, axis.y, axis.z));
			glm::vec3 up2 = trans2 * glm::vec4(0, 1, 0, 0);
			*/
			glm::mat4 ShadowViewMatrix = glm::lookAt(glm::vec3(0, 100, 0), glm::vec3(-1, 99.5, -1), glm::vec3(0, 1, 0));
			m_DepthShader->setUniformMat41("pr_matrix", ShadowProjectionMatrix);
			m_DepthShader->setUniformMat41("vw_matrix", ShadowViewMatrix);
			m_DepthShader->setUniform3f("campos", float3(40, 60, 40));
			//m_OceanShader->setUniform3f("lightdir", )

			for (int i = 0; i < m_PrimitiveSceneProxy.size(); i++)
			{
				mat4 worldmat = m_PrimitiveSceneProxy[i]->GetWorldMatrix();
				m_DepthShader->setUniformMat4("world_matrix", worldmat);
				Renderable* rb = m_PrimitiveSceneProxy[i]->getRenderable();
				rb->render();
			}
			m_DepthShader->disable();
			m_DepthTarget->UnBind();
		}


		void GameRenderer3::RenderScene(sparky::maths::mat4 viewmatrix)
		{


			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);
			glDisable(GL_BLEND);
			glClearColor(1, 1, 1, 1);
			glClearDepth(1);

			Texture* temp = m_DepthTarget->GetDepthStencilRenderTexture()->GetTexture();

			glm::mat4 ShadowProjectionMatrix = glm::ortho(-150.0f, 150.0f, -150.0f, 150.0f, 0.5f, 200.0f);
			glm::mat4 ShadowViewMatrix = glm::lookAt(glm::vec3(0, 100, 0), glm::vec3(-1, 99.5, -1), glm::vec3(0, 1, 0));

			glViewport(0, 0, 1920, 1080);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glm::mat4 mProjectionMatrix = glm::perspective(glm::radians(80.0f), 1.7777777778f, 0.1f, 1000.0f);

			m_SimpleShader->enable();

			m_SimpleShader->setUniformMat41("pr_matrix", mProjectionMatrix);
			//m_SimpleShader->setUniformMat41("view_matrix", mViewMatrix);
			m_SimpleShader->setUniformMat4("view_matrix", viewmatrix);
			//m_TestShader->setUniformMat41("world_matrix", mViewMatrix);
			m_SimpleShader->setUniform3f("campos", float3(40, 60, 40));
			
			m_SimpleShader->setUniform3f("lightdir", float3(-1, 0.5, -1));
		
			
			std::vector<float3> lightcolor;
			std::vector<float3> lightpos;

			lightcolor.push_back(float3(0.7360, 0.7360, 0.7360));
			lightpos.push_back(float3(0, 100, 0));
			/*lightpos.push_back(float3(150.0f, 200, 150.0f));
			lightpos.push_back(float3(-150.0f, 200, 150.0f));
			lightpos.push_back(float3(150.0f, 200, -150.0f));
			lightpos.push_back(float3(-150.0f,	200, -150.0f));*/
 
			//glm::vec3(0, 10, 0), glm::vec3(2, 8, 2)
			m_SimpleShader->SetUniform3fv("pointlightposition", lightpos);
			m_SimpleShader->setUniform1i("pointlightcount", lightpos.size());
			m_SimpleShader->SetUniform3fv("pointlightcolor", lightcolor);
			m_SimpleShader->SetTexture("shadowTex", temp, 0);
			//m_SimpleShader->SetTexture("clip2Shadow", temp);
			m_SimpleShader->setUniformMat41("shadowpr_matrix", ShadowProjectionMatrix);
			m_SimpleShader->setUniformMat41("shadowvw_matrix", ShadowViewMatrix);

			for (int i = 0; i < m_PrimitiveSceneProxy.size(); i++)
			{
				m_SimpleShader->setUniform4f("DiffuseColor", m_PrimitiveSceneProxy[i]->GetMaterial()->GetDiffuseColor());
				mat4 worldmat = m_PrimitiveSceneProxy[i]->GetWorldMatrix();
				m_SimpleShader->setUniformMat4("world_matrix", worldmat);

				Renderable* rb = m_PrimitiveSceneProxy[i]->getRenderable();
				rb->render();
				//}

			}
			m_SimpleShader->disable();
			//m_DepthTarget2->UnBind();

		}

	}
}
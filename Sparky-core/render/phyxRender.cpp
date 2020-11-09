#include "phyxRender.h"
#include "maths/util.h"
#include "render/mesh.h"
#include "maths/mat4.h"
#include "render/dynamicmesh.h"
#include "glm/gtc/matrix_transform.hpp"
#include "utils/fileutils.h"
#include "physics/PxObject.h"
using namespace sparky::maths;
using namespace sparky::graphics;


namespace sparky
{
	namespace render
	{


		PhyxRenderer::PhyxRenderer()
		{
		 
		 

		}
		void PhyxRenderer::Initialize()
		{

			m_OceanShader = new GraphicsShader("shaders/particle.vert", "shaders/particle.frag");

			DynamicMesh* newsoftmesh = new DynamicMesh();
			newsoftmesh= DynamicMesh::CreateMesh(24);
			m_SoftMesh.push_back(newsoftmesh);
		}



		void PhyxRenderer::Update(int i, std::vector<float3> pos)
		{
			m_SoftMesh[i]->Update(0, pos);
		}

		void PhyxRenderer::RenderScene()
		{

			glEnable(GL_BLEND);
			/*glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT_FACE);*/
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			/*glDisable(GL_CULL_FACE);*/
			//glEnable(GL_DEPTH_TEST);
			m_OceanShader->enable();



			glm::mat4 mViewMatrix = glm::lookAt(glm::vec3(0, 0.25f, -0.5f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
			glm::mat4 mProjectionMatrix = glm::perspective(90.0, 1.0, 0.1, 1000.0);


			m_OceanShader->setUniformMat41("pr_matrix", mProjectionMatrix);
			m_OceanShader->setUniformMat41("vw_matrix", mViewMatrix);
			m_OceanShader->setUniform3f("campos", float3(40, 60, 40));
			for (int i=0;i<m_SoftMesh.size();i++)
			{
				m_SoftMesh[i]->render();
			}
			
			m_OceanShader->disable();
		}

		void PhyxRenderer::AddRenderable(Renderable* r)
		{
			 

		}


	}
}

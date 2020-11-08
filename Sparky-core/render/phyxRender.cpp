#include "phyxRender.h"
#include "maths/util.h"
#include "render/mesh.h"
#include "maths/mat4.h"
#include "render/dynamicmesh.h"
#include "glm/gtc/matrix_transform.hpp"
#include "utils/fileutils.h"
 
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

			m_OceanShader = new GraphicsShader("shaders/ocean.vert", "shaders/ocean.frag");

	 
			
		}



		void PhyxRenderer::Update()
		{

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



			glm::mat4 mViewMatrix = glm::lookAt(glm::vec3(40, 60.0f, 40), glm::vec3(128, 0, 128), glm::vec3(0, 1, 0));
			glm::mat4 mProjectionMatrix = glm::perspective(90.0, 1.0, 0.1, 1000.0);


			m_OceanShader->setUniformMat41("pr_matrix", mProjectionMatrix);
			m_OceanShader->setUniformMat41("vw_matrix", mViewMatrix);
			m_OceanShader->setUniform3f("campos", float3(40, 60, 40));
 

			m_OceanShader->disable();
		}

		void PhyxRenderer::AddRenderable(Renderable* r)
		{
			 

		}


	}
}

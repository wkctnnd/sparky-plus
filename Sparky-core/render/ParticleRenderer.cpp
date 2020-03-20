#include "ParticleRenderer.h"
#include "maths/util.h"
#include "render/mesh.h"
#include "maths/mat4.h"

//#include ""
using namespace sparky::maths;
using namespace sparky::graphics;

#include "glm/gtc/matrix_transform.hpp"

namespace sparky
{
	namespace render
	{
		ParticleRenderer::ParticleRenderer()
		{
			
		}
		void ParticleRenderer::Initialize()
		{
	
			m_ParticleShader = new GraphicsShader("shaders/particle.vert", "shaders/particle.frag");


			
		}



		void ParticleRenderer::Update()
		{

			

		}

		void ParticleRenderer::RenderScene()
		{

			glEnable(GL_BLEND);
			/*glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT_FACE);*/
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			/*glDisable(GL_CULL_FACE);*/
			//glEnable(GL_DEPTH_TEST);
			m_ParticleShader->enable();

		

			glm::mat4 mViewMatrix = glm::lookAt(glm::vec3(0, 0.25f, -0.5f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
			glm::mat4 mProjectionMatrix = glm::perspective(90.0, 1.0, 0.1, 1000.0);


			m_ParticleShader->setUniformMat41("pr_matrix", mProjectionMatrix);
			m_ParticleShader->setUniformMat41("vw_matrix", mViewMatrix);
			 
			for (unsigned int i = 0; i < Particles.size(); i++)
			{
				Particles[i]->render();
			}

			m_ParticleShader->disable();
		}

		void ParticleRenderer::AddRenderable(Renderable* r)
		{
			Particles.push_back(r);

		}


	}
}

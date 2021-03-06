#include "skinmeshrenderer.h"
#include "maths/util.h"
#include "render/mesh.h"
#include "maths/mat4.h"

//#include ""
using namespace sparky::maths;
using namespace sparky::graphics;

#include "glm/gtc/matrix_transform.hpp"
#include "skeletalmesh.h"
#include "asset/skeleton.h"
namespace sparky
{
	namespace render
	{
		SkinMeshRenderer::SkinMeshRenderer(class SkeletalMesh* mesh)
		{
			m_SkeletalMesh = mesh;

		}

		void SkinMeshRenderer::Initialize()
		{

			m_SkinMeshShader = new GraphicsShader("shaders/skinmesh.vert", "shaders/skinmesh.frag");



		}



		void SkinMeshRenderer::Update()
		{
			m_SkeletalMesh->Update();


		}

		void SkinMeshRenderer::RenderScene()
		{

			//glEnable(GL_BLEND);
			/*glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT_FACE);*/
			//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			/*glDisable(GL_CULL_FACE);*/
			//glEnable(GL_DEPTH_TEST);
			m_SkinMeshShader->enable();




			glm::mat4 mViewMatrix = glm::lookAt(glm::vec3(0, 0.25f, -0.5f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
			glm::mat4 mProjectionMatrix = glm::perspective(90.0, 1.0, 0.1, 1000.0);

			m_SkinMeshShader->setUniformMat4v("BoneMatrix", &(m_SkeletalMesh->GetSkeleton()->SkinMat[0]), m_SkeletalMesh->GetSkeleton()->SkinMat.size());
			m_SkinMeshShader->setUniformMat41("pr_matrix", mProjectionMatrix);
			m_SkinMeshShader->setUniformMat41("vw_matrix", mViewMatrix);
			//m_SkinMeshShader->setUniform1i("BoneIndex0", 0);
			//m_SkinMeshShader->setUniform1i("BoneIndex1", 0);
			//m_SkinMeshShader->setUniform1i("BoneIndex2", 0);
			//m_SkinMeshShader->setUniform1i("BoneIndex3", 0);
			//m_SkinMeshShader->setUniformMat4v("BoneMatrix", )

			m_SkeletalMesh->Render();

			m_SkinMeshShader->disable();
		}
 


	}
}

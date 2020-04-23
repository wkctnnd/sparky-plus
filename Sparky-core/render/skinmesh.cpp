#include "graphics/buffers/staticbuffer.h"
#include "graphics/buffers/indexbuffer.h"
#include "Asset/rawskinmesh.h"
#include "Asset/fbxloader.h"
#include "skinmesh.h"
using namespace sparky::asset;
namespace sparky {
	namespace render {
		SkinMesh::SkinMesh(RawSkinMesh* rawskinmesh)
		{
			Buffer* buffer = new StaticBuffer(&(rawskinmesh->m_Position[0].x), rawskinmesh->m_Position.size() * 3, 3);
			Buffer* BoneWeightBuffer = new StaticBuffer(&(rawskinmesh->m_BoneWeight[0].x), rawskinmesh->m_BoneWeight.size() * 3, 3);
			Buffer* BoneIndexBuffer = new StaticBuffer(&(rawskinmesh->m_BoneIndex[0].x), rawskinmesh->m_BoneIndex.size() * 3, 3);
			IndexBuffer* ibuffer = new IndexBuffer(&rawskinmesh->m_Faces[0], rawskinmesh->m_Faces.size());
	
			m_VAO.addBuffer(buffer, 0);
			m_VAO.addBuffer(BoneWeightBuffer, 1);
			m_VAO.addBuffer(BoneIndexBuffer, 2);
			m_VAO.setIndexBuffer(ibuffer);
		}

		SkinMesh* SkinMesh::Load(const char* file)
		{
			
			FBXLoader fbxloader;
			fbxloader.LoadFile(file);
			fbxloader.LoadResources();

			RawSkinMesh* rawskinmesh = fbxloader.GetRawSkinMesh(0);
			
			Buffer* buffer = new StaticBuffer(&(rawskinmesh->m_Position[0].x), rawskinmesh->m_Position.size() * 3, 3);
			Buffer* BoneWeightBuffer = new StaticBuffer(&(rawskinmesh->m_BoneWeight[0].x), rawskinmesh->m_BoneWeight.size() * 3, 3);
			Buffer* BoneIndexBuffer = new StaticBuffer(&(rawskinmesh->m_BoneIndex[0].x), rawskinmesh->m_BoneIndex.size() * 3, 3);
			IndexBuffer* ibuffer = new IndexBuffer(&rawskinmesh->m_Faces[0], rawskinmesh->m_Faces.size());
			SkinMesh* newmesh = new SkinMesh(rawskinmesh);
			newmesh->m_VAO.addBuffer(buffer, 0);
			newmesh->m_VAO.addBuffer(BoneWeightBuffer, 1);
			newmesh->m_VAO.addBuffer(BoneIndexBuffer, 2);
			newmesh->m_VAO.setIndexBuffer(ibuffer);
			return newmesh;
		}

		void SkinMesh::render()
		{
			m_VAO.bind();
			if (m_VAO.Indexed())
				glDrawElements(GL_TRIANGLES, m_VAO.Indexcount(), GL_UNSIGNED_SHORT, 0);
			else
				glDrawArrays(GL_TRIANGLES, 0, 1);
			m_VAO.unBind();
		}
	}
}
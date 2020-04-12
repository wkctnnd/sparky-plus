#include "graphics/buffers/staticbuffer.h"
#include "graphics/buffers/indexbuffer.h"
#include "Asset/rawskinmesh.h"
#include "Asset/fbxloader.h"
#include "skinmesh.h"
using namespace sparky::asset;
namespace sparky {
	namespace render {
		SkinMesh* SkinMesh::Load(const char* file)
		{
			
			FBXLoader fbxloader;
			fbxloader.LoadFile(file);
			fbxloader.LoadResources();
			
			RawSkinMesh* rawskinmesh = fbxloader.GetRawSkinMesh(0);
			
			Buffer* buffer = new StaticBuffer(&(rawskinmesh->m_Position[0].x), rawskinmesh->m_Position.size() * 3, 3);
			Buffer* BoneWeightBuffer = new StaticBuffer(&(rawskinmesh->m_Weight[0].x), rawskinmesh->m_Weight.size() * 3, 3);
			Buffer* BoneIndexBuffer = new StaticBuffer(&(rawskinmesh->m_BoneIndex[0].x), rawskinmesh->m_BoneIndex.size() * 3, 3);
			IndexBuffer* ibuffer = new IndexBuffer(&rawskinmesh->m_Faces[0], rawskinmesh->m_Faces.size());
			SkinMesh* newmesh = new SkinMesh();
			newmesh->vao.addBuffer(buffer, 0);
			newmesh->vao.addBuffer(BoneWeightBuffer, 1);
			newmesh->vao.addBuffer(BoneIndexBuffer, 2);
			newmesh->vao.setIndexBuffer(ibuffer);
			return newmesh;
		}

		void SkinMesh::render()
		{
			vao.bind();
			if (vao.Indexed())
				glDrawElements(GL_TRIANGLES, vao.Indexcount(), GL_UNSIGNED_SHORT, 0);
			else
				glDrawArrays(GL_TRIANGLES, 0, 1);
			vao.unBind();
		}
	}
}
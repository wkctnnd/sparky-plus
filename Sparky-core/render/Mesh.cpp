#include "render/mesh.h"
#include "utils/fileutils.h"
#include "Asset/objloader.h"
#include "graphics/buffers/staticbuffer.h"
#include "graphics/buffers/indexbuffer.h"

using namespace sparky::asset;
namespace sparky {
	namespace render {
		Mesh* Mesh::Load(const char* file)
		{
			RawMesh rawmesh;
			objLoader::LoadMesh(file, rawmesh);
			Mesh* newmesh = Mesh::Load(rawmesh);

			return newmesh;
		}

		Mesh* Mesh::Load(RawMesh& rawmesh)
		{
			Mesh* newmesh = new Mesh();
			Buffer* buffer = new StaticBuffer(&(rawmesh.m_Position[0].x), rawmesh.m_Position.size() * 3, 3);
			newmesh->vao.addBuffer(buffer, 0);
			if (!rawmesh.m_Normal.empty())
			{
				Buffer* normalbuffer = new StaticBuffer(&(rawmesh.m_Normal[0].x), rawmesh.m_Normal.size() * 3, 3);
				newmesh->vao.addBuffer(normalbuffer, 1);
			}
			if (!rawmesh.m_Texcoord.empty())
			{
				Buffer* texcoordbuffer = new StaticBuffer(&(rawmesh.m_Texcoord[0].x), rawmesh.m_Texcoord.size() * 2, 2);
				newmesh->vao.addBuffer(texcoordbuffer, 2);
			}
			if (rawmesh.Indexed())
			{
				IndexBuffer* ibuffer = new IndexBuffer(&rawmesh.m_Faces[0], rawmesh.m_Faces.size());
				newmesh->vao.setIndexBuffer(ibuffer);
			}
				
			if (!rawmesh.m_Color.empty())
			{
				Buffer* colorbuffer = new StaticBuffer(&(rawmesh.m_Color[0].x), rawmesh.m_Color.size() * 4, 4);
				newmesh->vao.addBuffer(colorbuffer, 3);
			}
			
			
			return newmesh;
		}
		void Mesh::render()
		{
			vao.bind();
			if (vao.Indexed())
				glDrawElements(GL_TRIANGLES, vao.Indexcount(), GL_UNSIGNED_SHORT, 0);
			else
				glDrawArrays(GL_TRIANGLES, 0, vao.Vertexcout());
			vao.unBind();
		}
	}
}
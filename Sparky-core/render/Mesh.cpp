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
			Buffer* buffer = new StaticBuffer(&(rawmesh.m_Position[0].x), rawmesh.m_Position.size() * 3, 3);
			IndexBuffer* ibuffer = new IndexBuffer(&rawmesh.m_Faces[0], rawmesh.m_Faces.size());
			Mesh* newmesh = new Mesh();
			newmesh->vao.addBuffer(buffer, 0);
			newmesh->vao.setIndexBuffer(ibuffer);
			return newmesh;
		}
		void Mesh::render()
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
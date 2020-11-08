#include "dynamicmesh.h"
#include "maths/util.h"
#include "graphics/buffers/staticbuffer.h"
#include "graphics/buffers/DynamicBuffer.h"
#include "maths/mat4.h"


namespace sparky
{
	namespace render
	{
		float3 DynamicMesh::CaculateNormal(float3 a, float3 b, float3 c)
		{
			float3 vec0 = a - b;
			float3 vec1 = c - b;
			float3 normal = vec0.Cross(vec1).Normalize();
			return normal;

		}

		DynamicMesh* DynamicMesh::CreatePlaneMesh(unsigned int w, unsigned int h, float xsplit, float ysplit)
		{
			std::vector<float3> posarray;
			std::vector<float3> normalarray;
			
			std::vector<unsigned short> indexarray;
			std::vector<std::vector<float3>> triangleLink;
			for (unsigned int i=0;i<h;i++)
			{
				for (unsigned int j=0;j<w;j++)
				{
					//float3 temp();
				
					posarray.emplace_back(ysplit* i,0 , xsplit * j);
					
				}
			}


			triangleLink.resize(h*w * 2);
			/*for (int i=0;i<triangleLink.size();i++)
			{
				triangleLink[i].emplace_back();
			}*/
			for (unsigned int i = 0; i < h - 1; i++)
			{
				for (unsigned int j = 0; j < w - 1; j++)
				{
					indexarray.push_back(w * i + j);
					indexarray.push_back(w * i + j + 1);
					indexarray.push_back(w * (i+1) + j + 1);
					
					float3 normal0 = CaculateNormal(posarray[w * i + j], posarray[w*i + j + 1], posarray[w*(i + 1) + j + 1]);
					/*normalarray.push_back(normal0);*/
					triangleLink[w * i + j].push_back( normal0);
					triangleLink[w * i + j + 1].push_back(normal0);
					triangleLink[w * (i + 1) + j + 1].push_back(normal0);

					indexarray.push_back(w * i + j);
					indexarray.push_back(w * (i + 1) + j + 1);
					indexarray.push_back(w * (i + 1) + j);

					
					float3 normal1 = CaculateNormal(posarray[w * i + j], posarray[w * (i + 1) + j + 1], posarray[w * (i + 1) + j]);
					//normalarray.push_back(normal1);

					triangleLink[w * i + j].push_back(normal1);
					triangleLink[w * (i + 1) + j + 1].push_back(normal1);
					triangleLink[w * (i + 1) + j].push_back(normal1);
				}
			}

			for (int i = 0; i < triangleLink.size(); i++)
			{
				float3 normals(0, 0, 0);
				for (int j = 0; j < triangleLink[i].size(); j++)
				{
					normals = normals + triangleLink[i][j];
				}
				normals.NormalizeSelf();
				normalarray.push_back(normals);
				
			}
			Buffer* buffer = new DynamicBuffer(&posarray[0].x, posarray.size() * 3, 3);
			Buffer* buffer2 = new DynamicBuffer(&normalarray[0].x, normalarray.size() * 3, 3);
			IndexBuffer* ibuffer = new IndexBuffer(&indexarray[0], indexarray.size());

			DynamicMesh* newmesh = new DynamicMesh();
			newmesh->vao.addBuffer(buffer, 0);
			newmesh->vao.addBuffer(buffer2, 1);
			newmesh->vao.setIndexBuffer(ibuffer);
			return newmesh;
		}

		DynamicMesh* DynamicMesh::CreateMesh(int vertexcount)
		{
			Buffer* buffer = new DynamicBuffer(0, vertexcount * 3, 3);
			DynamicMesh* newmesh = new DynamicMesh();
			newmesh->vao.addBuffer(buffer, 0);
			//Buffer* buffer2 = new DynamicBuffer(&normalarray[0].x, normalarray.size() * 3, 3);
			return newmesh;
		}


		void DynamicMesh::render()
		{
			vao.bind();
			if (vao.Indexed())
				glDrawElements(GL_TRIANGLES, vao.Indexcount(), GL_UNSIGNED_SHORT, 0);
			else
				glDrawArrays(GL_TRIANGLES, 0, 1);
			vao.unBind();
		}

		//目前更新方式针对一个mesh独享buffer的情况，如果两个mesh共享一个buffer，更新一个buffer的时候会出现另外一个mesh也发生变化的情况
		void DynamicMesh::Update(unsigned int bufferid, std::vector<float3> newdata)
		{
			vao.updateBuffer(bufferid, &newdata[0].x,  3 * newdata.size()*sizeof(GLfloat));
		}
	}
}
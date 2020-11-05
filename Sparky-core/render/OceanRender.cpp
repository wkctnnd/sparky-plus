#include "OceanRender.h"
#include "maths/util.h"
#include "render/mesh.h"
#include "maths/mat4.h"
#include "render/dynamicmesh.h"
//#include ""
using namespace sparky::maths;
using namespace sparky::graphics;

#include "glm/gtc/matrix_transform.hpp"
#include "utils/fileutils.h"
namespace sparky
{
	namespace render
	{


		OceanRenderer::OceanRenderer(int width, int height)
		{
			Width = width;
			Height = height;
			posarray.resize(width*height);
			//framedataArray.resize(OceanFrames.size());
			
			
			//for (unsigned int i = 0; i < width; i++)
			//{
			//	for (unsigned int j = 0; j < height; j++)
			//	{
			//		//float3 temp();
			//		int index = i * width + j;
			//		posarray1[index].x = oceangirdsize * i;
			//		//posarray[index].y = OceanFrames[frameid][index];
			//		posarray1[index].z = oceangirdsize * j;

			//	}
			//}

			std::string fullrelativepath = FileUtile::GetCurrentWorkingDirectory() + std::string("\\..\\Assets\\height.txt");
			File.open(fullrelativepath.c_str());
			int framid = 0;
			if (File.is_open())          //文件打开成功,说明曾经写入过东西
			{
				char buf[1024];
				while (File.good() && !File.eof())
				{
					memset(buf, 0, 1024);
					File.getline(buf, 1204);
					std::string test(buf);
					if (test.find("frame") != -1)
					{
						
						if (framid > 60) break;
						OceanFrames.emplace_back();
						framid++;
					}
					else
					{
						int prevpos = 0;
						int pos = test.find(" ");
						/*float x = atof(test.substr(prevpos, pos - prevpos).c_str());
						prevpos = pos + 1;
						pos = test.find(" ", pos);
						float y = atof(test.substr(prevpos, pos - prevpos).c_str());
						prevpos = pos + 1;
						pos = test.find(" ", pos);*/
						float z = atof(test.substr(prevpos, pos - prevpos).c_str()) - 910;
						OceanFrames[OceanFrames.size() - 1].emplace_back(z);
					}
					
					
				}
				File.close();
			}


			for (int frameid = 0; frameid < OceanFrames.size(); frameid++)
			{
				framedata data;

				//framedata data = framedataArray[frameid];
				data.position.resize(width*height);
				data.normal.resize(width*height);
				for (unsigned int i = 0; i < width; i++)
				{
					for (unsigned int j = 0; j < height; j++)
					{
						//float3 temp();
						int index = i * width + j;
						data.position[index].x = oceangirdsize * i;
						data.position[index].y = OceanFrames[frameid][index];
						data.position[index].z = oceangirdsize * j;

					}
				}

				for (unsigned int i = 0; i < height - 1; i++)
			{
				for (unsigned int j = 0; j < width - 1; j++)
				{
					

					float3 normal0 = DynamicMesh::CaculateNormal(data.position[width * i + j], data.position[width*i + j + 1], data.position[width*(i + 1) + j + 1]);
					/*normalarray.push_back(normal0);*/
					data.normal[width * i + j] = normal0;
					data.normal[width * i + j + 1] = normal0;
					data.normal[width * (i + 1) + j + 1] = normal0;
					/*triangleLink[width * i + j].push_back(normal0);
					triangleLink[width * i + j + 1].push_back(normal0);
					triangleLink[width * (i + 1) + j + 1].push_back(normal0);*/



					float3 normal1 = DynamicMesh::CaculateNormal(data.position[width * i + j], data.position[width * (i + 1) + j + 1], data.position[width * (i + 1) + j]);
					//normalarray.push_back(normal1);
					data.normal[width * i + j] = normal1;
					data.normal[width * (i + 1) + j + 1] = normal1;
					data.normal[width * (i + 1) + j] = normal1;

				}
			}

				//for (unsigned int i = 0; i < height - 1; i++)
				//{
				//	for (unsigned int j = 0; j < width - 1; j++)
				//	{
				//		triangleLink[width * i + j].clear();
				//	}
				//}
				//for (unsigned int i = 0; i < height - 1; i++)
				//{
				//	for (unsigned int j = 0; j < width - 1; j++)
				//	{
				//		

				//		float3 normal0 = DynamicMesh::CaculateNormal(data.position[width * i + j], data.position[width*i + j + 1], data.position[width*(i + 1) + j + 1]);
				//		/*normalarray.push_back(normal0);*/
				//		triangleLink[width * i + j].push_back(normal0);
				//		triangleLink[width * i + j + 1].push_back(normal0);
				//		triangleLink[width * (i + 1) + j + 1].push_back(normal0);



				//		float3 normal1 = DynamicMesh::CaculateNormal(data.position[width * i + j], data.position[width * (i + 1) + j + 1], data.position[width * (i + 1) + j]);
				//		//normalarray.push_back(normal1);

				//		triangleLink[width * i + j].push_back(normal1);
				//		triangleLink[width * (i + 1) + j + 1].push_back(normal1);
				//		triangleLink[width * (i + 1) + j].push_back(normal1);
				//	}
				//}

				//for (int i = 0; i < width*height; i++)
				//{
				//	float3 normals(0, 0, 0);
				//	for (int j = 0; j < triangleLink[i].size(); j++)
				//	{
				//		normals = normals + triangleLink[i][j];
				//	}
				//	normals.NormalizeSelf();
				//	data.normal[i] = normals;

				//}
				framedataArray.push_back(data);
			}
		}
		void OceanRenderer::Initialize()
		{

			m_OceanShader = new GraphicsShader("shaders/ocean.vert", "shaders/ocean.frag");

			OceanMesh = DynamicMesh::CreatePlaneMesh(Width, Height, oceangirdsize, oceangirdsize);
			
		}



		//void OceanRenderer::Update()
		//{
		//	
		//	//std::vector<std::vector<float3>> triangleLink;
		//	std::vector<float3> normalarray;
		//	if (frameid < OceanFrames.size())
		//	{
		//		frameid = 0;
		//		

		//		for (unsigned int i = 0; i < Height; i++)
		//		{
		//			for (unsigned int j = 0; j < Width; j++)
		//			{
		//				//float3 temp();
		//				int index = i * Width + j;
		//				//posarray[index].x = oceangirdsize * i;
		//				posarray1[index].y = OceanFrames[frameid][index];
		//				//posarray[index].z = oceangirdsize * j;

		//			}
		//		}
		//		int h = Height;
		//		int w = Width;
		//		//triangleLink.resize(h*w * 2);
		//		for (unsigned int i = 0; i < h - 1; i++)
		//		{
		//			for (unsigned int j = 0; j < w - 1; j++)
		//			{
 

		//				float3 normal0 = DynamicMesh::CaculateNormal(posarray[w * i + j], posarray[w*i + j + 1], posarray[w*(i + 1) + j + 1]);
		//				/*normalarray.push_back(normal0);*/
		//				triangleLink[w * i + j].push_back(normal0);
		//				triangleLink[w * i + j + 1].push_back(normal0);
		//				triangleLink[w * (i + 1) + j + 1].push_back(normal0);

	 //

		//				float3 normal1 = DynamicMesh::CaculateNormal(posarray[w * i + j], posarray[w * (i + 1) + j + 1], posarray[w * (i + 1) + j]);
		//				//normalarray.push_back(normal1);

		//				triangleLink[w * i + j].push_back(normal1);
		//				triangleLink[w * (i + 1) + j + 1].push_back(normal1);
		//				triangleLink[w * (i + 1) + j].push_back(normal1);
		//			}
		//		}

		//		//for (int i = 0; i < triangleLink.size(); i++)
		//		//{
		//		//	float3 normals(0, 0, 0);
		//		//	for (int j = 0; j < triangleLink[i].size(); j++)
		//		//	{
		//		//		normals = normals + triangleLink[i][j];
		//		//	}
		//		//	normals.NormalizeSelf();
		//		//	normalarray.push_back(normals);

		//		//}


		///*		OceanMesh->Update(0, posarray);
		//		OceanMesh->Update(1, normalarray);*/
		//		frameid++;
		//	}
		//


		//}


		void OceanRenderer::Update()
		{

			//std::vector<std::vector<float3>> triangleLink;
			std::vector<float3> normalarray;
			if (frameid < OceanFrames.size())
			{
				


				OceanMesh->Update(0, framedataArray[frameid].position);
				OceanMesh->Update(1, framedataArray[frameid].normal);
				frameid++;
			}



		}

		void OceanRenderer::RenderScene()
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
			//m_OceanShader->setUniform3f("lightdir", )
			OceanMesh->render();

			m_OceanShader->disable();
		}

		void OceanRenderer::AddRenderable(Renderable* r)
		{
			 

		}


	}
}

#include "objloader.h"
#include "utils/fileutils.h"
#include "Asset/rawmesh.h"
#include "utils/File.h"
#include <sstream>
using namespace sparky::maths;
namespace sparky {

	namespace asset {
		bool objLoader::LoadMesh(const char* file, RawMesh& rmesh)
		{
			File f(file);
			std::string linestr = f.GetLine();
			float x, y, z;
			std::string head;
			std::vector<float3> positions;
			std::vector<float3> normals;
			std::vector<float2> texcoords;
			std::vector<unsigned short> faces;
			//std::vector<float2> texcoords;
			while (!linestr.empty())
			{

				if (linestr.length() < 2)continue;
				if (linestr[0] == 'v') {
					if (linestr[1] == 't') {//vt 0.581151 0.979929 纹理
						std::istringstream in(linestr);
						 
						in >> head >> x >> y;
						texcoords.emplace_back(x, y);
					/*	in >> head >> rmesh. >> vt->TV;
						m_pic.VT.push_back(*vt);*/

					}
					else if (linestr[1] == 'n') {//vn 0.637005 -0.0421857 0.769705 法向量
						std::istringstream in(linestr);

					 

						in >> head >> x >> y >> z;
						normals.emplace_back(x, y, z);

					}
					else {//v -53.0413 158.84 -135.806 点
						std::istringstream in(linestr);
						
						in >> head >> x >> y >> z;
						positions.emplace_back(x, y, z);

					}

				}
				else if (linestr[0] == 'f') {//f 2443//2656 2442//2656 2444//2656 面
					for (int k = linestr.size() - 1; k >= 0; k--) {
						if (linestr[k] == '/')linestr[k] = ' ';

					}
					std::istringstream in(linestr);
				 
					in >> head;
					int i = 0;
					int tempindex;
					while (i < 3)
					{
						if (positions.size() != 0)
						{
							in >> tempindex;
							tempindex -= 1;
							rmesh.m_Position.push_back(positions[tempindex]);
						}
						if (texcoords.size() != 0)
						{
							in >> tempindex;
							tempindex -= 1;
							rmesh.m_Texcoord.push_back(texcoords[tempindex]);
						}
						if (normals.size() != 0)
						{
							in >> tempindex;
							tempindex -= 1;
							rmesh.m_Normal.push_back(normals[tempindex]);
						}
						i++;
					}
					

				}
			}

			//create box
			/*rmesh.m_Position.push_back(float3(-1,-1,-1));
			rmesh.m_Position.push_back(float3(-1, -1, 1));
			rmesh.m_Position.push_back(float3(-1, 1, 1));
			rmesh.m_Position.push_back(float3(-1, 1, 1));
			rmesh.m_Position.push_back(float3(1, -1, -1));
			rmesh.m_Position.push_back(float3(1, -1, 1));
			rmesh.m_Position.push_back(float3(1, 1, 1));
			rmesh.m_Position.push_back(float3(1, 1, 1));

			rmesh.m_Faces.push_back(0);
			rmesh.m_Faces.push_back(1);
			rmesh.m_Faces.push_back(2);
			rmesh.m_Faces.push_back(0);
			rmesh.m_Faces.push_back(2);
			rmesh.m_Faces.push_back(3);

			rmesh.m_Faces.push_back(4);
			rmesh.m_Faces.push_back(5);
			rmesh.m_Faces.push_back(6);
			rmesh.m_Faces.push_back(4);
			rmesh.m_Faces.push_back(6);
			rmesh.m_Faces.push_back(7);

			rmesh.m_Faces.push_back(0);
			rmesh.m_Faces.push_back(4);
			rmesh.m_Faces.push_back(5);
			rmesh.m_Faces.push_back(0);
			rmesh.m_Faces.push_back(5);
			rmesh.m_Faces.push_back(1);

			rmesh.m_Faces.push_back(3);
			rmesh.m_Faces.push_back(7);
			rmesh.m_Faces.push_back(6);
			rmesh.m_Faces.push_back(3);
			rmesh.m_Faces.push_back(6);
			rmesh.m_Faces.push_back(2);


			rmesh.m_Faces.push_back(1);
			rmesh.m_Faces.push_back(5);
			rmesh.m_Faces.push_back(6);
			rmesh.m_Faces.push_back(6);
			rmesh.m_Faces.push_back(2);
			rmesh.m_Faces.push_back(1);


			rmesh.m_Faces.push_back(0);
			rmesh.m_Faces.push_back(4);
			rmesh.m_Faces.push_back(7);
			rmesh.m_Faces.push_back(0);
			rmesh.m_Faces.push_back(7);
			rmesh.m_Faces.push_back(3);*/

			return true;

			//rmesh.m_Faces.push_back(Face(0, 1, 2));
			//rmesh.m_Faces.push_back(Face(0, 2, 3));
			//rmesh.m_Faces.push_back(Face(4, 5, 6));
			//rmesh.m_Faces.push_back(Face(4, 6, 7));

			//rmesh.m_Faces.push_back(Face(0, 4, 5));
			//rmesh.m_Faces.push_back(Face(0, 5, 1));
			//rmesh.m_Faces.push_back(Face(3, 7, 6));
			//rmesh.m_Faces.push_back(Face(3, 6, 2));

			//rmesh.m_Faces.push_back(Face(1, 5, 6));
			//rmesh.m_Faces.push_back(Face(6, 2, 1));
			//rmesh.m_Faces.push_back(Face(0, 4, 7));
			//rmesh.m_Faces.push_back(Face(0, 7, 3));

		}
	}
}
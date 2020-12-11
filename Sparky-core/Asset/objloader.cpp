#include "objloader.h"
#include "utils/fileutils.h"
#include "Asset/rawmesh.h"
#include "utils/File.h"
#include <sstream>
#include "Asset/imageloader.h"
#include "Asset/material.h"
using namespace sparky::maths;
namespace sparky {

	namespace asset {
		bool objLoader::LoadMesh(const char* file, RawMesh& rmesh)
		{
			File f(file);
			std::string linestr = f.GetLine();
			float x, y, z;

			std::vector<std::string> matfile;
			std::string head;
			std::vector<float3> positions;
			std::vector<float3> normals;
			std::vector<float2> texcoords;
			std::vector<unsigned short> faces;
			//std::vector<float2> texcoords;
			while (!f.IsEnd())
			{

				if (linestr.length() < 2)
				{
					linestr = f.GetLine();
					continue;
				}
				if (linestr[0] == 'v') {
					if (linestr[1] == 't') {//vt 0.581151 0.979929 ����
						std::istringstream in(linestr);
						 
						in >> head >> x >> y;
						texcoords.emplace_back(x, y);
					/*	in >> head >> rmesh. >> vt->TV;
						m_pic.VT.push_back(*vt);*/

					}
					else if (linestr[1] == 'n') {//vn 0.637005 -0.0421857 0.769705 ������
						std::istringstream in(linestr);

					 

						in >> head >> x >> y >> z;
						normals.emplace_back(x, y, z);

					}
					else {//v -53.0413 158.84 -135.806 ��
						std::istringstream in(linestr);
						
						in >> head >> x >> y >> z;
						positions.emplace_back(x, y, z);

					}

				}
				else if (linestr[0] == 'f') {//f 2443//2656 2442//2656 2444//2656 ��
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
				else if (linestr[0]=='m')
				{
					std::istringstream in(linestr);
					std::string mat;
					in >> head >> mat;
				}

				linestr = f.GetLine();
			}


			return true;

	

		}



		bool objLoader::LoadFile(const char* file)
		{
			File f(file);
			std::string linestr = f.GetLine();
			float x, y, z;
			std::string head;
			std::vector<float3> positions;
			std::vector<float3> normals;
			std::vector<float2> texcoords;
			std::vector<unsigned short> faces;
			RawMesh* rmesh = new RawMesh();
			std::vector<std::string> matfile;
			//std::vector<float2> texcoords;
			while (!f.IsEnd())
			{

				if (linestr.length() < 2)
				{
					linestr = f.GetLine();
					continue;
				}
				if (linestr[0] == 'v') {
					if (linestr[1] == 't') {//vt 0.581151 0.979929 ����
						std::istringstream in(linestr);

						in >> head >> x >> y;
						texcoords.emplace_back(x, y);
						/*	in >> head >> rmesh. >> vt->TV;
							m_pic.VT.push_back(*vt);*/

					}
					else if (linestr[1] == 'n') {//vn 0.637005 -0.0421857 0.769705 ������
						std::istringstream in(linestr);



						in >> head >> x >> y >> z;
						normals.emplace_back(x, y, z);

					}
					else {//v -53.0413 158.84 -135.806 ��
						std::istringstream in(linestr);

						in >> head >> x >> y >> z;
						positions.emplace_back(x, y, z);

					}

				}
				else if (linestr[0] == 'f') {//f 2443//2656 2442//2656 2444//2656 ��
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
							rmesh->m_Position.push_back(positions[tempindex]);
						}
						if (texcoords.size() != 0)
						{
							in >> tempindex;
							tempindex -= 1;
							rmesh->m_Texcoord.push_back(texcoords[tempindex]);
						}
						if (normals.size() != 0)
						{
							in >> tempindex;
							tempindex -= 1;
							rmesh->m_Normal.push_back(normals[tempindex]);
						}
						i++;
					}


				}
				else if (linestr[0] == 'm')
				{
					std::istringstream in(linestr);
					std::string mat;
					in >> head >> mat;
					matfile.push_back(mat);
				}


				linestr = f.GetLine();
			}

			ImageLoader loader;
			for (int i=0;i<matfile.size();i++)
			{
				loader.LoadFile(matfile[i].c_str());
			}
		}

		//https://blog.csdn.net/weixin_34414196/article/details/91954612
		void LoadMaterial(const char* file)
		{
		
			File f(file);
			std::string linestr = f.GetLine();
			float x, y, z;
			Material* mat = new Material();

			std::string head;
			//std::vector<float2> texcoords;
			while (!f.IsEnd())
			{

				if (linestr.length() < 2)
				{
					linestr = f.GetLine();
					continue;
				}
				if (linestr[0] == 'K') {
					if (linestr[1] == 'a') {//vt 0.581151 0.979929 ����
						std::istringstream in(linestr);

						in >> head >> x >> y >> z;
						mat->m_Ambient.x = x;
						mat->m_Ambient.y = y;
						mat->m_Ambient.z = z;
					}
					else if (linestr[1] == 'd')
					{
						std::istringstream in(linestr);

						in >> head >> x >> y >> z;
						mat->m_Diffuse.x = x;
						mat->m_Diffuse.y = y;
						mat->m_Diffuse.z = z;
					}
					else if (linestr[1] = 's')
					{
						std::istringstream in(linestr);

						in >> head >> x >> y >> z;
						mat->m_Specular.x = x;
						mat->m_Specular.y = y;
						mat->m_Specular.z = z;
					}
				}
				if (linestr.substr(0,3).compare("map") ==0)
				{
					if (linestr.substr(4,2).compare("kd")==0)
					{

					}
				}
		}
		unsigned  int objLoader::GetMaterialCount()
		{ 
			return m_Materials.size();
		}
		class Material* objLoader::GetMaterial(unsigned int id) 
		{ 
			return m_Materials[id];
		}

	}
}
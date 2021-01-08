#include "objloader.h"
#include "utils/fileutils.h"
#include "Asset/rawmesh.h"
#include "utils/File.h"
#include <sstream>
#include "Asset/imageloader.h"
#include "Asset/material.h"
#include "global.h"
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
				else if (linestr[0] == 'm')
				{
					std::istringstream in(linestr);
					std::string mat;
					in >> head >> mat;
				}

				linestr = f.GetLine();
			}


			return true;



		}

		unsigned  int objLoader::GetMaterialCount()
		{
			return m_Materials.size();
		}
		class Material* objLoader::GetMaterial(unsigned int id)
		{
			if (m_Materials.size()>id)
			{
				return m_Materials[id];
			}
		
		}

		//支持加载一个mesh
		bool objLoader::LoadFile(std::string fileDir, std:: string filename)
		{
			std::string filepath = fileDir + filename;
			File f(filepath);

			std::string path(filepath);
			int i = path.find_last_of("//");
			CurrentFileDir = filepath.substr(0, i + 1);

			
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

			
			for (int i = 0; i < matfile.size(); i++)
			{
				std::string matfilepath = CurrentFileDir + matfile[i];
				LoadMaterial(matfilepath.c_str());
			}
			m_Meshs.push_back(rmesh);
			return true;
		}

		//https://blog.csdn.net/weixin_34414196/article/details/91954612
		void objLoader::LoadMaterial(const char* file)
		{
			//std::string fullrelativepath = FileUtile::GetCurrentWorkingDirectory() + std::string(AssetFilePath) + file;
			File f(file);
			if (f.IsInvalid())
			{
				return;
			}
			std::string linestr = f.GetLine();
			float x, y, z;
			Material* mat = new Material();
			ImageLoader imgloader;
			std::string head;
			//std::vector<float2> texcoords;
			while (!linestr.empty()||!f.IsEnd())
			{

				if (linestr.length() < 2)
				{
					linestr = f.GetLine();
					continue;
				}
				if (linestr[0] == 'K') {
					if (linestr[1] == 'a') {//vt 0.581151 0.979929 纹理
						std::istringstream in(linestr);

						in >> head >> x >> y >> z;
						mat->SetAmbientColor(x, y, z);

					}
					else if (linestr[1] == 'd')
					{
						std::istringstream in(linestr);

						in >> head >> x >> y >> z;
						mat->SetDiffuseColor(x, y, z);

					}
					else if (linestr[1] = 's')
					{
						std::istringstream in(linestr);

						in >> head >> x >> y >> z;
						mat->SetSpecularColor(x, y, z);
					}
				}
				std::string temp = linestr.substr(0, 3);
				if (temp.compare("map") == 0)
				{
					if (linestr.substr(4, 2).compare("Kd") == 0)
					{
						std::istringstream in(linestr);
						std::string texfilename;
						in >> head >> texfilename;
					 

						graphics::Texture* tex = imgloader.LoadFile((CurrentFileDir+ texfilename).c_str());
						mat->SetDiffuseMap(tex);
					}
				}
				linestr = f.GetLine();
			}

			m_Materials.push_back(mat);

		}





	}
}
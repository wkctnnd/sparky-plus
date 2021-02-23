#include "objloader.h"
#include "utils/fileutils.h"
#include "Asset/rawmesh.h"
#include "utils/File.h"
#include <sstream>
#include "Asset/imageloader.h"
#include "Asset/material.h"
#include "global.h"
#include <map>
using namespace sparky::maths;
namespace sparky {

	namespace asset {
		bool objLoader::LoadMesh(const char* file, RawMesh& rmesh)
		{
			File f(file);
			std::string linestr = f.GetLine();
			float x, y, z;
			MeshTrunk * CurrentTrunk;
			std::vector<std::string> matfile;
			std::string head;
			std::vector<float3> positions;
			std::vector<float3> normals;
			std::vector<float2> texcoords;
			std::vector<unsigned short> faces;
			std::map<std::string, int> matids;
			int matid = 0;
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
					CurrentTrunk->m_VertexOffset = rmesh.m_Position.size();
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
					CurrentTrunk->m_VertexCount = rmesh.m_Position.size() - CurrentTrunk->m_VertexCount + 1;

				}
				else if (linestr[0] == 'm')
				{
					std::istringstream in(linestr);
					std::string mat;
					in >> head >> mat;

				
				}

				else if (linestr.compare("usemtl"))
				{

					std::istringstream in(linestr);

					CurrentTrunk = new MeshTrunk();
					std::string trunckmatname;
					in >> head >> trunckmatname;
 
					auto itr = matids.find(trunckmatname);
					if (itr != matids.end())
					{
						CurrentTrunk->m_MaterialId = itr->second;

					}
					matids.insert(std::make_pair(trunckmatname, matid));
					CurrentTrunk->m_MaterialId = matid;
					matid++;
				
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
			if (!f.IsValid())
			{
				int a = 0;
			}
			std::string path(filepath);
			int i = path.find_last_of("//");
			CurrentFileDir = filepath.substr(0, i + 1);

			
			std::string linestr = f.GetLine();
			float x, y, z;
			std::string head;
			std::vector<float4> color;
			std::vector<float3> positions;
			std::vector<float3> normals;
			std::vector<float2> texcoords;
			std::vector<unsigned short> faces;
			RawMesh* rmesh = new RawMesh();
			std::vector<std::string> matfile;
		//	std::map<std::string, int> matids;
			MeshTrunk * CurrentTrunk = 0;
			int matid = 0;

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
						float cx = -1000000;
						float cy = -1000000;
						float cz = -1000000;
						in >> head >> x >> y >> z>>cx>>cy>>cz;
						positions.emplace_back(x, y, z);
						if(!(cx == -1000000&&cy== -1000000&&cz== -1000000))
							color.emplace_back(cx, cy, cz, 1);
					}

				}
				else if (linestr[0] == 'f') {//f 2443//2656 2442//2656 2444//2656 面
					for (int k = linestr.size() - 1; k >= 0; k--) {
						if (linestr[k] == '/')linestr[k] = ' ';

					}
					std::istringstream in(linestr);
					CurrentTrunk->m_VertexOffset = rmesh->m_Position.size();
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
							if (color.size() != 0)
							{
								 
								rmesh->m_Color.push_back(color[tempindex]);
							}
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
					CurrentTrunk->m_VertexCount = rmesh->m_Position.size() - CurrentTrunk->m_VertexOffset + 1;

				}
				else if (linestr[0] == 'm')
				{
					std::istringstream in(linestr);
					std::string mat;
					in >> head >> mat;
					matfile.push_back(mat);
				}

				else if (linestr.compare("usemtl"))
				{

					std::istringstream in(linestr);

					CurrentTrunk = new MeshTrunk();
					std::string trunckmatname;
					in >> head >> trunckmatname;

				/*	auto itr = matids.find(trunckmatname);
					if (itr != matids.end())
					{
						CurrentTrunk->m_MaterialId = itr->second;

					}
					matids.insert(std::make_pair(trunckmatname, matid));
					CurrentTrunk->m_MaterialId = matid;*/
					CurrentTrunk->m_MaterialName = trunckmatname;
					matid++;

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
			if (!f.IsValid())
			{
				return;
			}
			std::string linestr = f.GetLine();
			float x, y, z;
			Material* currentmat = 0;
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
				if (linestr[0]=='n')
				{
					if (linestr[1]=='e')
					{
						std::istringstream in(linestr);
						in>>head>>
					}
				}
				if (linestr.compare("newmtl")==0)
				{
					currentmat = new Material();
					m_Materials.push_back(currentmat);
					
				}
				if (linestr[0] == 'K') {
					if (linestr[1] == 'a') {//vt 0.581151 0.979929 纹理
						std::istringstream in(linestr);

						in >> head >> x >> y >> z;
						currentmat->SetAmbientColor(x, y, z);

					}
					else if (linestr[1] == 'd')
					{
						std::istringstream in(linestr);

						in >> head >> x >> y >> z;
						currentmat->SetDiffuseColor(x, y, z , 1);

					}
					else if (linestr[1] = 's')
					{
						std::istringstream in(linestr);

						in >> head >> x >> y >> z;
						currentmat->SetSpecularColor(x, y, z);
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
						currentmat->SetDiffuseMap(tex);
					}

					else if (linestr.substr(4, 4).compare("bump") == 0)
					{
						std::istringstream in(linestr);
						std::string texfilename;
						in >> head >> texfilename;


						graphics::Texture* tex = imgloader.LoadFile((CurrentFileDir + texfilename).c_str());
						currentmat->SetNormalMap(tex);
					}
				}
				linestr = f.GetLine();
			}

			

		}





	}
}
#include "stlloader.h"
#include "utils/file.h"
#include "Asset/rawmesh.h"
#include <string>
#include <sstream>
#include "Asset/rawmesh.h"
using namespace sparky::maths;
namespace sparky {

	namespace asset {
		bool stlLoader::LoadMesh(const char* file, RawMesh& rmesh)
		{
			File f(file);
			std::string linestr = f.GetLine();
			float a, b, c;
			std::string temp0, temp1;
			std::vector<float3> normal;
			std::vector<float3> position;

			 
			while (!linestr.empty())
			{

				if ((linestr.find("solid") == -1) && (linestr.find("outer loop") == -1) && (linestr.find("endloop") == -1) && (linestr.find("endfacet") == -1) && (linestr.find("endsolid") == -1))
				{
					if (linestr.find("facet normal") != -1)
					{
						
						std::istringstream in(linestr);
						in >> temp0 >> temp1 >> a >> b >> c;
						rmesh.m_Normal.emplace_back(a, b, c);
					 
					}
					else
					{
						std::istringstream in(linestr);
						in >> temp0 >> temp1 >> a >> b >> c;
				 
						rmesh.m_Position.emplace_back(a, b, c);

					}

				}
			}
	 


			

			return true;


		}
	}
}
#include "stlloader.h"
#include "utils/fileutils.h"
#include "Asset/rawmesh.h"
#include <string>
using namespace sparky::maths;
namespace sparky {

	namespace asset {
		bool stlLoader::LoadMesh(const char* file, RawMesh& rmesh)
		{

			std::string filestr = FileUtile::read_file(file);
			int begin= 0;
			int end = filestr.find("/0", begin);
			std::string linestr = filestr.substr(begin, end);
			while (!linestr.empty())
			{

				if ((linestr.find("solid") == -1) && (linestr.find("outer loop") == -1) && (linestr.find("endloop") == -1) && (linestr.find("endfacet") == -1) && (linestr.find("endsolid") == -1))
				{
					if (linestr.find("facet normal") != -1)
					{
						float a, b, c;
						sscanf(str, "%*s %*s %f %f %f", &a, &b, &c);
						o.AddNormal(a, b, c);
						o.AddNormal(a, b, c);
						o.AddNormal(a, b, c);
					 
					}
					else
					{
						float a, b, c;
						sscanf(str, "%*s  %f %f %f", &a, &b, &c);
						/* verts.push_back(a);
						 verts.push_back(b);
						 verts.push_back(c);*/
						o.AddPosition(a, b, c);

					}

				}
			}
			Objects.push_back(o);


			

			return true;


		}
	}
}
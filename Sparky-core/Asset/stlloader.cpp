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
						/*			vnorms.push_back(a);
									vnorms.push_back(b);
									vnorms.push_back(c);
									vnorms.push_back(a);
									vnorms.push_back(b);
									vnorms.push_back(c);
									vnorms.push_back(a);
									vnorms.push_back(b);
									vnorms.push_back(c);*/
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


			rmesh.m_Position.push_back(float3(-1, -1, -1));
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
			rmesh.m_Faces.push_back(3);

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
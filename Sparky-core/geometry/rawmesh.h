#pragma once
#include <vector>
#include "maths/vec3.h"
#include "maths/vec2.h"
using namespace sparky::maths;
namespace sparky
{
	namespace asset
	{

		/*struct Face
		{
			Face(unsigned int i, unsigned int j, unsigned int k)
			{
				m_VertexId[0] = i;
				m_VertexId[1] = j;
				m_VertexId[2] = k;
			}
			unsigned int m_VertexId[3];
		};*/
		struct RawMesh
		{
			std::vector<vec3> m_Position;
			std::vector<vec3> m_Normal;

			std::vector<unsigned short> m_Faces;
		};
	}
}

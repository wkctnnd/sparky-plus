#pragma once
#include <vector>
#include "maths/vec3.h"
#include "maths/vec2.h"
#include "maths/vec4.h"
#include "asset.h"
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
		class MeshTrunk
		{
		public:
			MeshTrunk() {};


			int m_MaterialId;
			std::string m_MaterialName;
			std::string m_MeshName;
			std::vector<unsigned short> m_Faces;

			int m_VertexOffset;
			int m_VertexCount;
		};

		class RawMesh :public Asset
		{
		public:
			RawMesh(std::string virtualpath, std::string name="") :Asset(virtualpath, name)
			{

			}

			RawMesh(std::string name="") :Asset(StaticMesh_Type, name)
			{

			}
			std::vector<float3> m_Position;
			std::vector<float4> m_Color;
			std::vector<float3> m_Normal;
			std::vector<float3> m_Tangent;
			std::vector<float2> m_Texcoord;

			std::vector<unsigned short> m_Faces;

			std::vector<MeshTrunk*> m_Trunks;
			bool Indexed() { return m_Faces.size() > 0; }
			void Optimize() {};
		};
	}
}

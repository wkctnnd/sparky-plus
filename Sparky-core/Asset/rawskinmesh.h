#pragma once

#include <vector>
#include "maths/vec3.h"
#include "maths/vec2.h"
#include "maths/vec4.h"
#include <string>
#include "skeleton.h"
#include "asset.h"
using namespace sparky::maths;
namespace sparky
{
	namespace asset
	{
		//struct joint
		//{
		//	joint(joint* p, std::string n)
		//	{
		//		name = n;
		//		parent = p;

		//	}
		//	std::string name;
		//	float3 position;
		//	joint* parent;
		//	std::vector<joint*> children;
		//};
		//struct Skeleton
		//{
		//	std::vector<joint*> joints;
		//};

		struct RawSkinMesh:public Asset
		{
			RawSkinMesh(std::string virtualpath, std::string name = "") :Asset(AssetType::SkinMesh_Type, virtualpath ,name)
			{

			}

			RawSkinMesh(std::string name = "") :Asset(SkinMesh_Type,name)
			{

			}
			std::vector<float3> m_Position;
			std::vector<float4> m_Color;
			std::vector<float3> m_Tangent;
			std::vector<float3> m_Normal;
			std::vector<float4> m_BoneWeight;
			std::vector<int4> m_BoneIndex;
			std::vector<unsigned short> m_Faces;
			//Skeleton m_Skeleton;
			//std::string m_RootBoneName;
			bool Indexed() { return m_Faces.size() > 0; }
		};
	}
}

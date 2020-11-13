#pragma once
#include <vector>
#include "maths/vec3.h"
#include "maths/mat4.h"
#include "maths/quaternion.h"
#include "animation/property.h"

using namespace sparky::maths;
using namespace sparky::animation;
namespace sparky
{
	namespace asset
	{
		struct joint
		{
			joint(joint* p, std::string n):m_Translation(Translate_Property_Type, n),m_Scale(Scale_Property_Type, n), m_Quat(Rotation_Property_Type, n)
			{
				bonename = n;
				parent = p;
				IsUpdated = false;;
			}

			joint(joint* p) :m_Translation(Translate_Property_Type), m_Scale(Scale_Property_Type), m_Quat(Rotation_Property_Type)
			{
				bonename = p->bonename;
				parent = p;
				IsUpdated = false;;
			}
			
			int m_Id;
			std::string bonename;
			//wostd::string 
			//float3 position;
			mat4 InvBoneMatrix;
			mat4 TransMatrix;
			mat4 InvTransMatrix;

			Property<float3> m_Translation;
			Property<float3> m_Scale;
			Property<Quaternion> m_Quat;

			//for simple use, for now it is for kinect
			float3 m_SimpleTranslation;
			float3 m_SimpleScale;
			Quaternion m_SimpleQuat;
			
			joint* parent;
			std::vector<joint*> children;

			bool IsUpdated;
		};
		struct Skeleton
		{
			Skeleton()
			{

			}
			Skeleton(int size)
			{
				WorldPose.resize(size);
				SkinMat.resize(size);
			}
			void UpdateWorldMatrix();

			//for simple use
			void ManualUpdateWorldMatrix();
			std::vector<joint*> joints;
			std::vector<mat4> WorldPose;
			std::vector<mat4> SkinMat;
			void Reset() { for (int i = 0; i < joints.size(); i++) joints[i]->IsUpdated = false; }
			bool Check()
			{
				for (int i = 0; i < joints.size(); i++)
					if (!joints[i]->IsUpdated)
					{
						return false;
					}
				return true;
			}
		private:
			void UpdateJoint(unsigned long elapse, joint* j);
			void ManualUpdateJoint( joint* j);
			void SetRoot(std::string rootname);

			int m_Root;
		};
	}
}
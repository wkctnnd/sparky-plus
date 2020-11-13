#pragma once
#include "Asset/skeleton.h"
#include "engine.h"
#include "maths/mat4.h"
#include "Asset/skeleton.h"
using namespace sparky::maths;
using namespace sparky::animation;
namespace sparky
{
	namespace asset
	{
		void Skeleton::UpdateWorldMatrix()
		{
			long elapse = Engine::GlobalTimer.GetElapsemillionseconds();
			std::cout << elapse<<std::endl;
			UpdateJoint(elapse, joints[0]);

		}

		void Skeleton::ManualUpdateWorldMatrix()
		{
			ManualUpdateJoint(joints[0]);
		}

		void Skeleton::SetRoot(std::string rootname)
		{
			for (int i=0;i< joints.size();i++)
			{
				if (joints[i]->bonename.compare(rootname) == 0)
				{
					m_Root = i;
				}
			}
		}

		void Skeleton::ManualUpdateJoint( joint* j)
		{
			if (j->bonename.compare("Humanoid:LeftShoulder_Dummy") == 0)
			{

				int a = 1;
			}

			mat4 TranslateMat = mat4::Translate(j->m_SimpleTranslation);
			mat4 RotateMat = mat4::rotation(j->m_SimpleQuat);
			mat4 ScaleMat = mat4::scale(j->m_SimpleScale);


			//if(j->parent)
			//	WorldPose[j->m_Id] = WorldPose[j->parent->m_Id] * TranslateMat * RotateMat * ScaleMat;
			//else 
			//	WorldPose[j->m_Id] = TranslateMat * RotateMat * ScaleMat;

			if (j->parent)
			{
				mat4 temp = RotateMat * ScaleMat;
				mat4 temp2 = TranslateMat * temp;
				WorldPose[j->m_Id] = WorldPose[j->parent->m_Id] * temp2;
			}

			else
			{
				/*mat4 mat;
				mat.elements[0] = 0.165;
				mat.elements[1] = 0;
				mat.elements[2] = 0;
				mat.elements[3] = 0;
				mat.elements[4] = 0;
				mat.elements[5] = 0.00000000026223f;
				mat.elements[6] = -0.165;
				mat.elements[7] = 0;
				mat.elements[8] = 0;
				mat.elements[9] = 0.165;
				mat.elements[10] = 0.00000000026223f;
				mat.elements[11] = 0;
				mat.elements[12] = 0;
				mat.elements[13] = 0;
				mat.elements[14] = 0;
				mat.elements[15] = 1;*/
				WorldPose[j->m_Id] = TranslateMat * RotateMat * ScaleMat;
			}

			//* joints[j->m_Id]->InvBoneMatrix

			mat4 temp = joints[j->m_Id]->InvBoneMatrix * joints[j->m_Id]->TransMatrix;

			SkinMat[j->m_Id] = joints[j->m_Id]->InvTransMatrix * WorldPose[j->m_Id] * temp;
			j->IsUpdated = true;
			for (int i = 0; i < j->children.size(); i++)
			{
				ManualUpdateJoint( j->children[i]);


			}
		}

		void Skeleton::UpdateJoint(unsigned long elapes, joint *j)
		{

	 
			if (j->bonename.compare("Humanoid:LeftShoulder_Dummy") == 0)
			{

				int a = 1;
			}

			//elapes = 0;
			float3 translate(0,0,0);
			float3 scale(1, 1, 1);
			Quaternion quat(1, 0, 0, 0);
			j->m_Translation.EvaluateValue(elapes, translate);
			j->m_Scale.EvaluateValue(elapes, scale);
			j->m_Quat.EvaluateValue(elapes, quat);

			mat4 TranslateMat = mat4::Translate(translate);
			mat4 RotateMat = mat4::rotation(quat);
			mat4 ScaleMat = mat4::scale(scale);
			
			
			//if(j->parent)
			//	WorldPose[j->m_Id] = WorldPose[j->parent->m_Id] * TranslateMat * RotateMat * ScaleMat;
			//else 
			//	WorldPose[j->m_Id] = TranslateMat * RotateMat * ScaleMat;

			if (j->parent)
			{
				mat4 temp = RotateMat * ScaleMat;
				mat4 temp2 = TranslateMat*temp;
				WorldPose[j->m_Id] = WorldPose[j->parent->m_Id] * temp2;
			}
				
			else
			{
				/*mat4 mat;
				mat.elements[0] = 0.165;
				mat.elements[1] = 0;
				mat.elements[2] = 0;
				mat.elements[3] = 0;
				mat.elements[4] = 0;
				mat.elements[5] = 0.00000000026223f;
				mat.elements[6] = -0.165;
				mat.elements[7] = 0;
				mat.elements[8] = 0;
				mat.elements[9] = 0.165;
				mat.elements[10] = 0.00000000026223f;
				mat.elements[11] = 0;
				mat.elements[12] = 0;
				mat.elements[13] = 0;
				mat.elements[14] = 0;
				mat.elements[15] = 1;*/
				WorldPose[j->m_Id] = TranslateMat * RotateMat * ScaleMat;
			}
				
			//* joints[j->m_Id]->InvBoneMatrix

			mat4 temp = joints[j->m_Id]->InvBoneMatrix * joints[j->m_Id]->TransMatrix;
		 
			SkinMat[j->m_Id] = joints[j->m_Id]->InvTransMatrix * WorldPose[j->m_Id] * temp;
			j->IsUpdated = true;
			for (int i = 0; i < j->children.size(); i++)
			{
				UpdateJoint(elapes, j->children[i]);


			}
		}
	
	}
}
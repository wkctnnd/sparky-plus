#pragma once
#include "skeletalmesh.h"
#include "animation/controller.h"
#include "Asset/skeleton.h"
#include "animation/animationstack.h"
#include "animation/animationlayer.h"
#include "animation/property.h"
#include "skinmesh.h"
namespace sparky
{
	namespace render {

		SkeletalMesh::SkeletalMesh(class SkinMesh* skinmesh, class Skeleton * skeleton)
		{
			m_SkinMesh = skinmesh;
			m_Skeleton = skeleton;
			/*m_Skeleton->*/
		}
		SkinMesh* SkeletalMesh::GetRenderable()
		{
			return 0;
		}
		void SkeletalMesh::Update()
		{
			m_Skeleton->Reset();
			m_Skeleton->UpdateWorldMatrix();
			m_Skeleton->Check();
		}
		void SkeletalMesh::Render()
		{
			m_SkinMesh->render(); 
		}
		
		void SkeletalMesh::SetController(Controller* controller)
		{
			m_Controller = controller; 
		/*	for (int i = 0; i < m_Controller->GetAnimationStackCount(); i++)
			{*/
				AnimationStack * stack = m_Controller->GetAnimationStack(0);
				BindProperty(stack, m_Skeleton);
			/*}*/

		}
		void SkeletalMesh::BindProperty(AnimationStack* stack, Skeleton* skeleton)
		{
			for (int i = 0; i < skeleton->joints.size(); i++)
			{
				for (int j = 0; j < stack->GetAnimationLayerCount(); j++)
				{
					AnimationLayer *layer = stack->GetAnimationLayer(j);


					auto& property = skeleton->joints[i]->m_Translation;
					auto& property2 = skeleton->joints[i]->m_Quat;
					auto& property3 = skeleton->joints[i]->m_Scale;
		/*			for (int k = 0; k < layer->GetKeyValueNodeCount(); k++)
					{*/
						KeyValueNodeBase* KeyValueNode = layer->GetKeyValueNode(skeleton->joints[i]->bonename, property.GetType());
						if (KeyValueNode != 0)
						{
							property.BindKeyValueNode(KeyValueNode, 1);		
						}

						KeyValueNode = layer->GetKeyValueNode(skeleton->joints[i]->bonename, property2.GetType());
						if (KeyValueNode != 0)
						{
							property2.BindKeyValueNode(KeyValueNode, 1);
						}
						
						KeyValueNode = layer->GetKeyValueNode(skeleton->joints[i]->bonename, property3.GetType());
						if (KeyValueNode != 0)
						{
							property3.BindKeyValueNode(KeyValueNode, 1);
						}
					/*}*/
				}
			}
		}
	}
}
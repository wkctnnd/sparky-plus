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
		}
		SkinMesh* SkeletalMesh::GetRenderable()
		{
			return 0;
		}
		void SkeletalMesh::Update()
		{
			m_Skeleton->UpdateWorldMatrix();
		}
		void SkeletalMesh::Render()
		{
			m_SkinMesh->render(); 
		}
		
		void SkeletalMesh::SetController(Controller* controller)
		{
			m_Controller = controller; 
			for (int i = 0; i < m_Controller->GetAnimationStackCount(); i++)
			{
				AnimationStack * stack = m_Controller->GetAnimationStack(i);
				BindProperty(stack, m_Skeleton);
			}

		}
		void SkeletalMesh::BindProperty(AnimationStack* stack, Skeleton* skeleton)
		{
			for (int i = 0; i < skeleton->joints.size(); i++)
			{
				for (int j = 0; j < stack->GetAnimationLayerCount(); j++)
				{
					AnimationLayer *layer = stack->GetAnimationLayer(j);

					auto& property = skeleton->joints[i]->m_Translation;
					auto& property2 = skeleton->joints[i]->m_Translation;
					auto& property3 = skeleton->joints[i]->m_Translation;
					for (int i = 0; i < layer->GetKeyValueNodeCount(); i++)
					{
						KeyValueNodeBase* KeyValueNode = layer->GetKeyValueNode(i);
						if (property.GetType() == layer->GetKeyValueNode(i)->GetType())
						{
							property.BindKeyValueNode(KeyValueNode, 1);
			
						}
						if (property2.GetType() == layer->GetKeyValueNode(i)->GetType())
						{
							property2.BindKeyValueNode(KeyValueNode, 1);
						}
						
						if (property3.GetType() == layer->GetKeyValueNode(i)->GetType())
						{
							property3.BindKeyValueNode(KeyValueNode, 1);
						}
					}
				}
			}
		}
	}
}
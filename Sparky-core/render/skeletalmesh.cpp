#pragma once
#include "skeletalmesh.h"
#include "animation/controller.h"
#include "Asset/skeleton.h"
#include "animation/animationstack.h"
namespace sparky
{
	namespace render {

		SkinMesh* SkeletalMesh::GetRenderable()
		{

		}
		void SkeletalMesh::Update()
		{

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
					skeleton->joints[i]->m_Translation
				}
				
			}
		}
 
	}
}
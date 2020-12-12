#include "animationmanager.h"
#include "controller.h"
#include "engine.h"
using namespace sparky::asset;
namespace sparky
{
	namespace animation
	{
		AnimationManager* AnimationManager::m_AnimationManager = 0;
		AnimationManager* AnimationManager::INSTANCE()
		{
			if (!m_AnimationManager)
			{
				m_AnimationManager = new AnimationManager();
			}
			return m_AnimationManager;
		}

		SkeletonPose* AnimationManager::GetPose(unsigned int id, long duration)
		{
			SkeletonPose* clip = 0;


			return clip;
		}

		int AnimationManager::GetAnimationId(std::string& name)
		{
			/*auto iterator = m_ClipId.find(name);
			if (iterator != m_ClipId.end())
			{
				return m_ClipId[name];
			}*/
			return -1;
		}

		void AnimationManager::Update()
		{
			unsigned long elapse = Engine::GlobalTimer.GetElapsemillionseconds();
			for (int i = 0; i < m_Controller.size(); i++)
			{
				m_Controller[i]->Update();
			}
		}
	}
}
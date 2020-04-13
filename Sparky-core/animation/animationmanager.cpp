#include "animationmanager.h"
using namespace sparky::asset;
namespace sparky
{
	namespace animation
	{
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
			SkeletonClip* clip = m_Clips[id];


			return clip;
		}

		int AnimationManager::GetAnimationId(std::string& name)
		{
			auto iterator = m_ClipId.find(name);
			if (iterator != m_ClipId.end())
			{
				return m_ClipId[name];
			}
			return -1;
		}
	}
}
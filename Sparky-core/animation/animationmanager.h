#pragma once
#include <vector>
#include <string>
#include <map>
namespace sparky
{
	namespace asset
	{
		struct SkeletonPose;
	}
}
using namespace sparky::asset;
namespace sparky
{
	namespace animation
	{
		class AnimationManager
		{
		public:
			const std::string& GetAnimationName() const;
	
			void Update();

			SkeletonPose* GetPose(unsigned int id, long duration);
			int GetAnimationId(std::string& name);
			AnimationManager* INSTANCE();
		protected:
			std::vector<class SkeletonClip*> m_Clips;
			//std::map<std::string, unsigned int> m_ClipId;
			static AnimationManager* m_AnimationManager;
			AnimationManager() {}

			std::vector<class Controller*> m_Controller;                          
		};
	}
}

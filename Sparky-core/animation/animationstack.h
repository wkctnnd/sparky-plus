#pragma once
#include <vector>
namespace sparky
{
	namespace animation
	{
		class AnimationLayer;

		//����һ��������Դ����ֻ����һ��layer
		class AnimationStack
		{
		public:
			AnimationStack(std::string name) { m_Name = name; }
			void AddLayer(AnimationLayer *, float);
			int GetAnimationLayerCount() { return m_BlendLayers.size(); }
			AnimationLayer* GetAnimationLayer(int id) { return m_BlendLayers[id]; };
		private:
			std::vector<AnimationLayer *> m_BlendLayers;
			std::vector<float> m_BlendWeights;
			std::string m_Name;
		};

	}
}

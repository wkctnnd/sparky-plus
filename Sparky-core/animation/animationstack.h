#pragma once
#include <vector>
namespace sparky
{
	namespace animation
	{
		class AnimationLayer;

	}
}

using namespace sparky::animation;


//����һ��������Դ����ֻ����һ��layer
class AnimationStack
{
public:
	void AddLayer(AnimationLayer *, float);
private:
	std::vector<AnimationLayer *> m_BlendLayers;
	std::vector<float> m_BlendWeights;
};
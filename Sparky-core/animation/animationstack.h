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


//完整一个动画资源，暂只考虑一个layer
class AnimationStack
{
public:
	void AddLayer(AnimationLayer *, float);
private:
	std::vector<AnimationLayer *> m_BlendLayers;
	std::vector<float> m_BlendWeights;
};
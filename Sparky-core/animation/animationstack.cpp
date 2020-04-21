#include "animationstack.h"


void AnimationStack::AddLayer(AnimationLayer * layer, float weight)
{
	m_BlendWeights.push_back(weight);
	m_BlendLayers.push_back(layer);
}

#pragma once
#pragma once
#include <vector>
#include "skeleton.h"
#include "maths/vec3.h"
#include "maths/mat4.h"
#include "maths/quaternion.h"
using namespace sparky::maths;
namespace sparky
{
	namespace asset
	{
		struct Pose
		{
			vec3 translate;
			vec3 scale;
			Quaternion quat;
		};

		struct SkeletonPose
		{
			SkeletonPose(unsigned long span, unsigned int fcount)
			{
				milliseconds = span;
				framecount = fcount;
			}
			unsigned long milliseconds;
			unsigned int framecount;
			std::vector<Pose> LocalPose;
			std::vector<mat4> WorldPos;
		};


		class AnimationClip
		{

		private:
			SkeletonPose* m_ClipPose;
		};

		class AnimationStack
		{


		private:
			std::vector<AnimationClip*> m_Layers;
			std::vector<float> m_BlendWeights;
		};
	}
}
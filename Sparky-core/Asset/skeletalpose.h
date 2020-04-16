#pragma once
#pragma once
#include <vector>
#include "skeleton.h"
#include "maths/vec3.h"
#include "maths/mat4.h"
#include "maths/quaternion.h"
#include "animation/keyvalue.h"
using namespace sparky::maths;
using namespace sparky::animation;
namespace sparky
{
	namespace asset
	{
		//struct SkeletonPose
		//{
		//	SkeletonPose(vec3 t, vec3 s, Quaternion q)
		//	{
		//		translate = t;
		//		scale = s;
		//		quat = q;
		//	}
		//	vec3 translate;
		//	vec3 scale;
		//	Quaternion quat;
		//};

		struct SkeletonPose
		{
			//SkeletonPose()
			//{

			//}
			//Property<vec3> Translate;
			//Property<vec3> scale;
			//Property<Quaternion> quat;
		};

		/*struct SkeletonClip
		{
			SkeletonClip(unsigned long span, unsigned int fcount)
			{
				milliseconds = span;
				framecount = fcount;
			}
			unsigned long milliseconds;
			unsigned int framecount;
	

			std::vector<SkeletonPose> LocalPose;
			std::vector<mat4> WorldPose;
		};*/

		struct SkeletonClip
		{
			SkeletonClip(unsigned long span, unsigned int fcount)
			{
				milliseconds = span;
				framecount = fcount;
			}
			unsigned long milliseconds;
			unsigned int framecount;


			SkeletonPose LocalPose;
			std::vector<mat4> WorldPose;
		};


		class AnimationClip
		{

		private:
			SkeletonClip* m_ClipPose;
		};

		class AnimationStack
		{


		private:
			std::vector<AnimationClip*> m_Layers;
			std::vector<float> m_BlendWeights;
		};
	}
}
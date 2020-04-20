#pragma once

#include"graphics/buffers/vertexarray.h"
#include "render/renderable.h"
#include "graphics/buffers/indexbuffer.h"
#include "animation/animationstate.h"
using namespace sparky::graphics;
using namespace sparky::animation;
namespace sparky
{
	namespace render {

		class SkeletalMesh  
		{
		public:
 
			class SkinMesh* GetRenderable();
			void Update();
		private:
			
			class SkinMesh* m_SkinMesh;
			class Skeleton* m_Skeleton;
		};
	}
}
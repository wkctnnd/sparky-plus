#pragma once

#include"graphics/buffers/vertexarray.h"
#include "render/renderable.h"
#include "graphics/buffers/indexbuffer.h"
#include "animation/animationstate.h"
namespace sparky
{
	namespace animation
	{
		class Controller;
		class AnimationStack;
		class Skeleton;
	}
}
using namespace sparky::graphics;
using namespace sparky::animation;
namespace sparky
{
	namespace render {

		class SkeletalMesh  
		{
		public:

			//未来考虑挪到animation component中
			void SetController(Controller* controller);


			class SkinMesh* GetRenderable();
			void Update();
		private:
			
			//暂时只绑定骨骼property
			void BindProperty(class AnimationStack* layer, Skeleton* skeleton);

			class SkinMesh* m_SkinMesh;
			class Skeleton* m_Skeleton;

			class Controller* m_Controller;
		};
	}
}
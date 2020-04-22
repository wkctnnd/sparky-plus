#pragma once

#include"graphics/buffers/vertexarray.h"
#include "render/renderable.h"
#include "graphics/buffers/indexbuffer.h"
 
namespace sparky
{
	namespace animation
	{
		class Controller;
		class AnimationStack;
		

	}
}




namespace sparky
{
	namespace asset
	{
		class Skeleton;
	}
}
using namespace sparky::animation;
using namespace sparky::graphics;
using namespace sparky::asset;

//using sparky::animation::AnimationStack;


namespace sparky
{
	namespace render {
		//class AnimationStack;
		class SkeletalMesh  
		{
		public:
			SkeletalMesh(class SkinMesh* skinmesh, class Skeleton * skeleton);
			//未来考虑挪到animation component中
			void SetController(Controller* controller);


			class SkinMesh* GetRenderable();
			void Update();
		private:
			
			//暂时只绑定骨骼property
			

			void BindProperty(AnimationStack* layer, Skeleton* skeleton);

			class SkinMesh* m_SkinMesh;
			class Skeleton* m_Skeleton;

			class Controller* m_Controller;
		};
	}
}


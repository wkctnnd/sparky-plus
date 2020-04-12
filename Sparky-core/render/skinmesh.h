#pragma once
#include"graphics/buffers/vertexarray.h"
#include "render/renderable.h"
#include "graphics/buffers/indexbuffer.h"
using namespace sparky::graphics;
namespace sparky
{
	namespace render {

		class SkinMesh :public Renderable
		{
		public:
			void render();
			static SkinMesh* Load(const char* file);
			void SetCurrentPose(class SkeletonPose* pose);
		private:
			VertexArray  vao;
			
			class SkeletonPose* m_Pose;
		};
	}
}
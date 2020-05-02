#pragma once
#include"graphics/buffers/vertexarray.h"
#include "render/renderable.h"
#include "graphics/buffers/indexbuffer.h"
namespace sparky
{
	namespace asset
	{
		class RawSkinMesh;
	}
}
using namespace sparky::graphics;
using namespace sparky::asset;
namespace sparky
{
	namespace render {

		class SkinMesh :public Renderable
		{
		public:
			SkinMesh(class RawSkinMesh* rawskinmesh);
			void render();
			static SkinMesh* Load(const char* file);
			//std::string GetRootBoneName() { return m_RawSkinMesh->m_RootBoneName; }
			//void SetCurrentPose(class SkeletonClip* pose);
		private:
			VertexArray  m_VAO;
			
			class RawSkinMesh *m_RawSkinMesh;
			//class SkeletonClip* m_Pose;
		};
	}
}
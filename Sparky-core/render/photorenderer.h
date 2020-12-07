#pragma once
#include "maths/vec4.h"
#include "graphics/shader/computeshader.h"
#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/computebuffer.h"
#include <vector>
using namespace sparky::maths;
using namespace sparky::graphics;
using namespace std;
namespace sparky {
	namespace world
	{
		class Scene;
		class PrimitiveSceneProxy;
	}
}

namespace sparky {
	namespace render {


		class Renderable;
		class PhotoRenderer
		{
		public:

		private:
			GraphicsShader * m_ParticleShader;
			//m_ParticleVertexShader
		public:
			PhotoRenderer(world::Scene* scene);
			void Initialize();
			void Update();

			void RenderScene(float3 position,float3 axis, float angle);
			void RenderSceneDepth(float3 position, float3 axis, float angle);
			void PostUpdate();
			void RenderSceneTest();
			void AddRenderable(Renderable* r);

		private:
			vector<Renderable*> PhotoObjects;
			GraphicsShader * m_PhotoShader;
			GraphicsShader* m_DepthShader;
			GraphicsShader* m_TestShader;
			world::Scene* m_Scene;

			vector<world::PrimitiveSceneProxy*> m_PrimitiveSceneProxy;
		};
	}
}

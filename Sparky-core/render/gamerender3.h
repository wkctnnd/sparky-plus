#pragma once
#include "maths/vec4.h"
#include "graphics/shader/computeshader.h"
#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/computebuffer.h"
#include <vector>
using namespace sparky::maths;

using namespace std;
namespace sparky {
	namespace world
	{
		class Scene;
		class PrimitiveSceneProxy;
	}
	namespace graphics
	{
		class RenderTargetInfo;
	}
}

namespace sparky {
	namespace render {


		class Renderable;
		class GameRenderer3
		{

			//m_ParticleVertexShader
		public:
			GameRenderer3(world::Scene* scene);
			void Initialize();
			void Update();


			void PostUpdate();
			void RenderScene(float3 position, float3 axis, float angle);
			void RenderScene(maths::mat4 viewmatrix);
			void AddRenderable(Renderable* r);

		private:
			vector<Renderable*> PhotoObjects;
			graphics::GraphicsShader * m_DepthShader;
			graphics::GraphicsShader* m_SimpleShader;

			world::Scene* m_Scene;
			graphics::RenderTargetInfo* m_DepthTarget;
			graphics::RenderTargetInfo* m_DepthTarget2;
			vector<world::PrimitiveSceneProxy*> m_PrimitiveSceneProxy;
		};
	}
}

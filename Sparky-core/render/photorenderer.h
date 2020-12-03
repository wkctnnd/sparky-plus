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

			void RenderScene();
			void PostUpdate();
			void AddRenderable(Renderable* r);

		private:
			vector<Renderable*> PhotoObjects;
			GraphicsShader * m_PhotoShader;

			world::Scene* m_Scene;
		};
	}
}

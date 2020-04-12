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
	namespace render {


		class Renderable;
		class SkinMeshRenderer
		{
		public:

		private:
			GraphicsShader * m_SkinMeshShader;
			//m_ParticleVertexShader
		public:
			SkinMeshRenderer();
			void Initialize();
			void Update();

			void RenderScene();

			void AddRenderable(Renderable* r);

		private:
			vector<Renderable*> Particles;
		};
	}
}
#pragma once

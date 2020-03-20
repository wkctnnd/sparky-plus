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
		class ParticleRenderer
		{
		public:

		private:
			GraphicsShader * m_ParticleShader;
			//m_ParticleVertexShader
		public:	
			ParticleRenderer();
			void Initialize();
			void Update();

			void RenderScene();
			 
			void AddRenderable(Renderable* r);

		private:
			vector<Renderable*> Particles;
		};
	}
}

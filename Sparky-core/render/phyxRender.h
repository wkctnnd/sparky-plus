#pragma once
#pragma once

#include "maths/vec4.h"
#include "graphics/shader/computeshader.h"
#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/computebuffer.h"
#include <vector>
#include <fstream>

using namespace sparky::maths;
using namespace sparky::graphics;
using namespace std;


namespace sparky {
	namespace phyx
	{
		class PxObject;
	}
	namespace render {

		class DynamicMesh;
		class Renderable;
		 
		class PhyxRenderer
		{
		public:

		private:
			GraphicsShader * m_OceanShader;
			//m_ParticleVertexShader
		public:
			PhyxRenderer();
			void Initialize();
			void Update(sparky::phyx::PxObject* object);

			void RenderScene();

			void AddRenderable(Renderable* r);

		private:
			DynamicMesh* m_SoftMesh;
			 
			
		 
	 


 
		};
	}
}

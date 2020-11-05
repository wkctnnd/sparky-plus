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
	namespace render {

		class DynamicMesh;
		class Renderable;
		class framedata
		{
		public:
			std::vector<float3> position;
			std::vector<float3> normal;
		};
		class OceanRenderer
		{
		public:

		private:
			GraphicsShader * m_OceanShader;
			//m_ParticleVertexShader
		public:
			OceanRenderer(int width, int height);
			void Initialize();
			void Update();

			void RenderScene();

			void AddRenderable(Renderable* r);

		private:
			DynamicMesh* OceanMesh;
			std::vector<std::vector<float>> OceanFrames;
			ifstream File;
			int frameid;
			float oceangirdsize = 10;
			std::vector<float3> posarray;
			float3 posarray1[65535];
			float3 normal[65535];
			std::vector<float3> triangleLink[65536];

			std::vector<framedata> framedataArray;
			int Width;
			int Height;
		};
	}
}

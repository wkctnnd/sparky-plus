#pragma once
#include"graphics/buffers/vertexarray.h"
#include "render/renderable.h"
#include "graphics/buffers/indexbuffer.h"
#include "maths/vec3.h"
using namespace sparky::graphics;
 
using namespace sparky::maths;
namespace sparky
{
	namespace render {

	
		class DynamicMesh :public Renderable
		{
		public:
			void render();
			static DynamicMesh* CreatePlaneMesh(unsigned int w, unsigned int h, float xsplit, float ysplit);
			static DynamicMesh* CreateMesh(int vertexcount);
			static float3 CaculateNormal(float3 a, float3 b, float3 c);
		
			void Update(unsigned int bufferid, std::vector<float3> newdata);
		private:
			VertexArray  vao;
			std::vector<float3> posarray;
		};
	}
}
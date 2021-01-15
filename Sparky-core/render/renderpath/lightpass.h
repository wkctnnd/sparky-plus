#pragma once
#include "pass.h"
#include "graphics/shader/graphicsshader.h"
namespace sparky
{

	namespace render
	{
		class LightShader :public graphics::GraphicsShader
		{
		public:
			LightShader(const char* vertPath, const char* fragPath) :graphics::GraphicsShader(vertPath, fragPath)
			{

			}
			void GetShaderBinding(class graphics::ShaderBinding* sb, world::PrimitiveSceneProxy* primitiveproxy, world::LightSceneProxy* lightproxy);

		};




		class LightPass :public Pass
		{
		public:
			void AddMeshDrawCommand(world::PrimitiveSceneProxy* psp, world::Scene* scene);
			void Process();

		private:
			//GraphicsShader * m_ToonShader;
			LightShader* m_LightShader;
		};
	}
}

#pragma once
namespace sparky
{
	namespace graphics
	{

		class GraphicsPipelineState
		{
		public:
			void Bind(class ShaderBinding* bind);
			class GraphicsShader* m_Shader;
		};
	}
}
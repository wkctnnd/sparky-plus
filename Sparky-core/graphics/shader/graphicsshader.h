#pragma once
#include "shader.h"

namespace sparky {
	namespace world
	{
		class PrimitiveSceneProxy;
		class LightSceneProxy;
	}
	namespace graphics {
		//Ŀǰ��������shaderƬ��
		class GraphicsShader :public Shader
		{
		public:
			void GetShaderBinding(class ShaderBinding* sb, world::PrimitiveSceneProxy* primitiveproxy, world::LightSceneProxy* lightproxy);
			GraphicsShader(const char* vertPath, const char* fragPath);
		private:
			GLuint load();
			const char*m_VertPath, *m_FragPath;
		};
	}
}
#pragma once
#include <vector>
namespace sparky
{
	namespace graphics
	{
		class GraphicsShader;
		class GraphicsPipelineState;
		class ShaderBinding;
	}
	namespace render
	{
		class DrawCommmand
		{
		public:
			DrawCommmand(class Renderable* renable, graphics::GraphicsPipelineState* gps)
			{
				m_Gps = gps;
				m_Renderable = renable;

			}


			void Execute();

			static DrawCommmand* CreateDrawCommand(class Renderable* renable, graphics::GraphicsPipelineState* gps, graphics::ShaderBinding* shaderbinding)
			{
				DrawCommmand *command = new DrawCommmand(renable, gps);
				m_CommandList.push_back(command);
				return command;
			}
			
			static std::vector<class DrawCommmand*> m_CommandList;

		private:
			graphics::GraphicsPipelineState* m_Gps;
			class Renderable* m_Renderable;
			graphics::ShaderBinding *m_ShaderBinding;
		};
	}
}


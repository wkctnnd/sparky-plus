#include "shadowpass.h"
#include "render/renderpath/rendercommand/DrawCommand.h"
#include "world/PrimitiveSceneProxy.h"
#include "graphics/graphicpiplinestate.h"
#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/shaderbinding.h"
namespace sparky
{
	namespace render
	{
		void ShadowPass::AddMeshDrawCommand(world::PrimitiveSceneProxy* psp, world::Scene* lightproxy)
		{
			graphics::GraphicsShader* shader = new graphics::GraphicsShader("shaders/depth.vert", "shaders/depth.frag");
			graphics::GraphicsPipelineState* gps = new graphics::GraphicsPipelineState();
			gps->m_Shader = shader;
			
			graphics::ShaderBinding sb; 
			DrawCommmand::CreateDrawCommand(psp->getRenderable(), gps, &sb);
		}


		void ShadowPass::Process()
		{

		}
	}
}
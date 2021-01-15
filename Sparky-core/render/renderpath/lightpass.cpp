#include "lightpass.h"
#include "render/renderpath/rendercommand/DrawCommand.h"
#include "world/PrimitiveSceneProxy.h"
#include "graphics/graphicpiplinestate.h"
#include "graphics/shader/graphicsshader.h"
#include "world/lightsceneproxy.h"
#include "graphics/shader/shaderbinding.h"
#include "world/lightsceneproxy.h"
#include "world/scene.h"

using namespace sparky::world;
using namespace sparky::graphics;
namespace sparky
{
	namespace render
	{
		void LightShader::GetShaderBinding(ShaderBinding* sb, world::PrimitiveSceneProxy* primitiveproxy, world::LightSceneProxy* lightproxy)
		{

		}


		void LightPass::AddMeshDrawCommand(world::PrimitiveSceneProxy* psp, world::Scene* scene)
		{
			if (psp)
			{
				render::LightShader* shader = new render::LightShader("shaders/basepass.vert", "shaders/basepass.frag");
				graphics::ShaderBinding sb;
				for (int i=0;i<scene->GetLightNum();i++)
				{
					world::LightSceneProxy* lightproxy = scene->GetLight(i);
					if (lightproxy->GetType()== LightType::DirectionalLightType)
					{
						shader->GetShaderBinding(&sb, psp, lightproxy);
						graphics::GraphicsPipelineState* gps = new graphics::GraphicsPipelineState();
						gps->m_Shader = shader;
						DrawCommmand::CreateDrawCommand(psp->getRenderable(), gps, &sb);
					}
				}
			

			
			}
		}


		void LightPass::Process()
		{

		}
	}
}
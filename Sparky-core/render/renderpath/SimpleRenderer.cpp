#include "SimpleRenderer.h"

namespace sparky
{
	namespace render
	{
		void SimpleRenderer::AddPass(world::PrimitiveSceneProxy* psp)
		{
			m_Passes[LightPass]->AddMeshDrawCommand(psp, m_Scene);
		}
	}
}
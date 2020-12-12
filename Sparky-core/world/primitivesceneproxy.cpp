#include "PrimitiveSceneProxy.h"

namespace sparky
{
	namespace world
	{
		PrimitiveSceneProxy::PrimitiveSceneProxy(render::Renderable* rb, render::RenderMaterial* mat, mat4 wm)
		{
			m_Mesh = rb;
			m_WorldMatrix = wm;
			m_Materal = mat;
		}
	}
}
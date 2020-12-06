#include "PrimitiveSceneProxy.h"

namespace sparky
{
	namespace world
	{
		PrimitiveSceneProxy::PrimitiveSceneProxy(render::Renderable* rb, mat4 wm)
		{
			m_Mesh = rb;
			m_WorldMatrix = wm;
		}
	}
}
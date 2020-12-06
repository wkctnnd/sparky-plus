#pragma once
#include "maths/mat4.h"
#include "SceneProxy.h"
using namespace sparky::maths;
namespace sparky
{
	namespace render
	{
		class  Renderable;
	}
}
namespace sparky
{
	namespace world
	{
		
		class PrimitiveSceneProxy:public SceneProxy
		{
		public:
			PrimitiveSceneProxy(render::Renderable* rb, mat4 wm);
			render::Renderable* getRenderable() { return m_Mesh; };
			mat4 GetWorldMatrix() { return m_WorldMatrix; }

		protected:

			mat4 m_WorldMatrix;
			render::Renderable* m_Mesh;
		};

	}
}

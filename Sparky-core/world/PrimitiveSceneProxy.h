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

	namespace render
	{
		class RenderMaterial;
	}
}
namespace sparky
{
	namespace world
	{
		
		class PrimitiveSceneProxy:public SceneProxy
		{
		public:
			//material�˴�ֻ�ǵ��룬��Ҫ��һЩ����ļӹ����ݣ��˴�Ϊ��ʱ
			PrimitiveSceneProxy(render::Renderable* rb, render::RenderMaterial* mat, mat4 wm);
			render::Renderable* getRenderable() { return m_Mesh; };
			mat4 GetWorldMatrix() 
			{ 
				return m_WorldMatrix; 
			}

			render::RenderMaterial *GetMaterial() { return m_Materal; }
		protected:

			mat4 m_WorldMatrix;
			render::Renderable* m_Mesh;
			render::RenderMaterial* m_Materal;
		};

	}
}

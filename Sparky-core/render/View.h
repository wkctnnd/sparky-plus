#pragma once
#include "maths/vec3.h"
#include <vector>
#include "utils/container/bitarray.h"
using namespace sparky::maths;
using namespace sparky::container;
//用于视口渲染，可以根据当前相机位置裁剪获得可视列表，更新相机有关的uniformbuffer

namespace sparky
{
	namespace render
	{
		class View
		{
		public:
			View() {}
			View(float3 location, float3 direction, float3 up, float fov, float aspect, int width);
			//void 
			void UpdateViewUniformBuffer();
			//void AddSceneProxy(class PrimitiveSceneProxy* sceneporxy);

			void UpdateVisibleSet();
		private:


			float3 m_ViewLocation;
			float3 m_ViewForwrd;
			float3 m_ViewRight;
			float m_Fov;
			float m_Aspect;
			float m_Width;

			std::vector<class PrimitiveSceneProxy*> m_SceneProxyArray;
			//BitArray  m_VisibleArray;

		};
	}
}

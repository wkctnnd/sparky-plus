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
			//void 
			void UpdateViewUniformBuffer();
			//void AddSceneProxy(class PrimitiveSceneProxy* sceneporxy);

			void UpdateVisibleSet();


			void SetViewLocation(float3 location);
			void SetViewForward(float3 forward);
			void SetViewRight(float3 right);

			static int GetViewCount() { return m_ViewArray.size(); }
			static View* GetView(int i) { return m_ViewArray[i]; }
		private:



			static std::vector<View*> m_ViewArray;

			float3 m_ViewLocation;
			float3 m_ViewForwrd;
			float3 m_ViewRight;


			BitArray  m_VisibleArray;

		};
	}
}

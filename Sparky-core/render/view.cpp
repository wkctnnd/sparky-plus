#include "View.h"

namespace sparky
{
	namespace render
	{
		void View::UpdateViewUniformBuffer()
		{

		}
		//void AddSceneProxy(class PrimitiveSceneProxy* sceneporxy);

		void View::UpdateVisibleSet()
		{

		}


		void View::SetViewLocation(float3 location)
		{
			m_ViewLocation = location;
		}
		void View::SetViewForward(float3 forward)
		{
			m_ViewForwrd = forward;
		}
		void View::SetViewRight(float3 right)
		{
			m_ViewRight = right;
		}
	}
}
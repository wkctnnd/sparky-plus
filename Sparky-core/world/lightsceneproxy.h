#pragma once
#include "world/SceneProxy.h"
namespace sparky
{
	namespace world
	{
		enum LightType
		{
			DirectionalLightType,
			SpotLightType,
			PointLightType
		};
		class LightSceneProxy :public SceneProxy
		{
		public:
			LightType GetType()
			{
				return DirectionalLightType;
			}


		private:
 
		};
	}
}

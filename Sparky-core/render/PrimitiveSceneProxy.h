#pragma once
#include "sceneproxy.h"

namespace sparky
{
	namespace render
	{
		class PrimitiveSceneProxy:public SceneProxy
		{
		public:
			bool ShouldeRenderShadow();
		

		private:
			class Material *m_Material;
		};

	}
}

#pragma once

#include "maths/vec4.h"
#include "graphics/shader/computeshader.h"
#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/computebuffer.h"
#include <vector>
#include <fstream>
#include "pass.h"
#include <vector>
using namespace sparky::maths;
using namespace sparky::graphics;
using namespace std;
namespace sparky
{
	namespace world
	{
		class PrimitiveSceneProxy;
	}
}

namespace sparky {
	namespace render {


		class SceneRenderer
		{
		public:
			SceneRenderer(world::Scene* scene)
			{
				m_Passes.resize(PassType::PassNum);
				m_Scene = scene;
			}
			virtual void Render() = 0;
			virtual void AddSceneProxy() = 0;

			virtual void AddPass(world::PrimitiveSceneProxy* psp) = 0;
		protected:
			std::vector<Pass*> m_Passes;
			world::Scene* m_Scene;
		
		};
	}
}

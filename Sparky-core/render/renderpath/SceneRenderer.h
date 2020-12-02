#pragma once

#include "maths/vec4.h"
#include "graphics/shader/computeshader.h"
#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/computebuffer.h"
#include <vector>
#include <fstream>

using namespace sparky::maths;
using namespace sparky::graphics;
using namespace std;


namespace sparky {
	namespace render {


		class SceneRenderer
		{
		public:
			virtual void Render() = 0;
			virtual void AddSceneProxy() = 0;

		};
	}
}

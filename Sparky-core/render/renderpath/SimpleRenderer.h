#pragma once

#include "maths/vec4.h"
#include "graphics/shader/computeshader.h"
#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/computebuffer.h"
#include <vector>
#include <fstream>
#include "SceneRenderer.h"
using namespace sparky::maths;
using namespace sparky::graphics;
using namespace std;


namespace sparky {
	namespace render {

 
		class SimpleRenderer:public SceneRenderer
		{
		public:
			void Render();
			
	 
		};
	}
}

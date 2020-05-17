#pragma once

#include"graphics/buffers/vertexarray.h"
#include "render/renderable.h"
#include "graphics/buffers/indexbuffer.h"
using namespace sparky::graphics;
namespace sparky
{
	namespace render
	{
		class Pass
		{
		public:
			virtual void Render() = 0;


		};
	}
}
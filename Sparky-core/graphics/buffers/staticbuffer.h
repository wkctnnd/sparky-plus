#pragma once
#include "buffer.h"

namespace sparky
{
	namespace graphics
	{
		class StaticBuffer :public Buffer
		{
		public:
			StaticBuffer(float* data, int count, unsigned int componentCount);

	 
		};
	}
}


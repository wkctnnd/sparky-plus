#pragma once
#include "buffer.h"

namespace sparky
{
	namespace graphics
	{
		class StaticBuffer :public Buffer
		{
		public:
			StaticBuffer(void* data, int count, unsigned int componentCount);

	 
		};
	}
}


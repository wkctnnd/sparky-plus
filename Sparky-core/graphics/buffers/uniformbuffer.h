#pragma once
#include "buffer.h"
namespace sparky
{
	namespace graphics
	{
		class UniformBufferParameter
		{

		};


		class UniformBuffer :public Buffer
		{
		public:
			UniformBuffer(GLfloat* data, GLsizei datasize, bool dynamic);

			void Update();
			void bind() const;
			void unBind() const;
		};
	}
}

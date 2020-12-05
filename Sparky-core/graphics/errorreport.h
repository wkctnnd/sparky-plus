#pragma once
#include <string>
#include <gl/glew.h>
namespace sparky {
	namespace graphics {

		enum ErrorCode
		{
			NO_ERROR =  0,
			INVALID_ENUM,
			INVALID_VALUE,
			INVALID_OPERATION,
			STACK_OVERFLOW,
			STACK_UNDERFLOW,
			OUT_OF_MEMORY,
			INVALID_FRAMEBUFFER_OPERATION,
			CONTEXT_LOST
		};

		class ErrorReport
		{
		public:
			static ErrorCode GetError()
			{
				GLenum error = glGetError();
				if (error == GL_NO_ERROR)
				{
					return NO_ERROR;
				}
				else if (error==GL_INVALID_ENUM)
				{
					return INVALID_ENUM;
				}
				else if (error == GL_INVALID_VALUE)
				{
					return INVALID_VALUE;
				}
				else if (error == GL_INVALID_OPERATION)
				{
					return INVALID_OPERATION;
				}
				else if (error ==GL_STACK_OVERFLOW)
				{
					return STACK_OVERFLOW;
				}
				else if (error == GL_STACK_UNDERFLOW)
				{
					return STACK_UNDERFLOW;
				}
				else if (error == GL_OUT_OF_MEMORY)
				{
					return OUT_OF_MEMORY;
				}
				else if (error == GL_INVALID_FRAMEBUFFER_OPERATION)
				{
					return INVALID_FRAMEBUFFER_OPERATION;
				}
				else if (error == GL_CONTEXT_LOST)
				{
					return CONTEXT_LOST;
				}
			}
		};
	}
}
#pragma once
#include "buffer.h"
#include "maths/vec3.h"
#include "maths/vec4.h"
#include <vector>
using namespace sparky::maths;
namespace sparky
{
	namespace graphics
	{
		class UniformBufferParameter
		{
		public:
	 
			struct ElementLayout
			{
				ElementLayout()
				{
					offset = 0;
					bytecount = 0;
					realbytecount = 0;
				}
				int offset;
				int bytecount;
				int realbytecount;
			};
			void AddElement(float value);
			void AddElement(float3 value);
			void AddElement(float4 value);
			//void AddElement(class graphics::Texture2D* value);

		private:

			std::vector<ElementLayout> m_Layout;
		};



		class UniformBuffer :public Buffer
		{
		public:
			UniformBuffer(GLfloat* data, GLsizei datasize, bool dynamic);

			
			void bind() const;
			void unBind() const;
		};
	}
}

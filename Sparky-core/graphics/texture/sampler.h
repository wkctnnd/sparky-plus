#pragma once
#include <gl/glew.h>
#include <string>
namespace sparky
{
	namespace graphics
	{

	 


		enum WarpMode
		{
			RPEAT,
			CLAMP
		};
		class Sampler
		{
		public:

			Sampler();
			virtual void Bind() const;
			virtual void UnBind() const;

		protected:
			int m_TexId;
			int m_Width;
			int m_Height;
			int m_Depth;
			Format m_Formt;
			WarpMode m_WarpMode;
		};

	}
}

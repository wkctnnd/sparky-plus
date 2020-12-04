#include "texture.h"

using namespace sparky::maths;
namespace sparky
{
	namespace graphics
	{
		Texture::Texture(int w, int h, int depth, Format f)
		{
			m_Height = h;
			m_Width = w;
			m_Formt = f;
		}
	}
}
 
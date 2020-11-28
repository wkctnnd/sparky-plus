#pragma once
#include "texture2d.h"
namespace sparky {
	namespace graphics {

		class RenderTexture
		{
		public:
			RenderTexture(int width, int height, Format format) {};

			Texture* GetTexture() { return m_Texture; }
			virtual void ReadPixel(int offsetx, int offsety, int width, int height, void* data) = 0;

			virtual void SaveToDisk(std::string file) = 0;
		protected:
			Texture* m_Texture;

		};

	}
}
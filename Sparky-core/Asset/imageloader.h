#pragma once
namespace sparky
{
	namespace asset
	{
		class ImageLoader
		{
		public:
			bool LoadFile(const char* file);
			void LoadResources();
		};
	}
}
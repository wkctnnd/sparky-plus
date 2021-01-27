#pragma once
#include <string>
namespace sparky
{
	namespace asset
	{
		class Asset
		{
		public:
			Asset(std::string path)
			{
				m_VirtualPath = path;
			}
			std::string GetVirtualPath()
			{
				return m_AssetPath;
			}

		protected:
			std::string m_AssetPath;
			std::string m_VirtualPath;
		};
	}
}

#pragma once
#include <string>
#include <fstream>
#define  MAX_PATH 1000
namespace sparky {
	class File
	{
	public:
		File() {}
		File(std::string path)
		{
			OpenFile(path);
		}
		void OpenFile(std::string path);

		std::string GetLine();
	private:
		std::ifstream m_FileIn;
	};

}
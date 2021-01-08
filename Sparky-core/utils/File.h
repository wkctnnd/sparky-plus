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
		bool IsInvalid() { return m_Invalid; }
		void OpenFile(std::string path);
		bool IsEnd();
		std::string GetLine();
	private:
		std::ifstream m_FileIn;
		bool m_Invalid;
	};

}
#pragma once
#include <string>
#include <fstream>
#define  MAX_PATH 1000
namespace sparky {
	enum FileMode
	{
		File_Read,
		File_Write,
		File_ReadWrite
	};
	class File
	{
	public:
		File() {}
		File(std::string path, FileMode mode = File_Read)
		{
			this->mode = mode;
			OpenFile(path, mode);
		}
		bool IsValid() { return m_Valid; }
		void OpenFile(std::string path, FileMode mode = File_Read);
		bool IsEnd();
		std::string GetLine();
		void WriteLine(std::string line);
	private:
		std::ifstream m_FileIn;
		std::ofstream m_FileOut;
		std::fstream m_FileInOut;
		bool m_Valid;

		FileMode mode;
	};

}
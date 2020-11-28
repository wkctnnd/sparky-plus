#pragma once
#include <string>
#include <direct.h>
#include <fstream>
#define  MAX_PATH 1000
namespace sparky {
	class FileUtile
	{
	public:
		static  std::string read_file(const char* filepath)
		{
			FILE* file = nullptr;
			fopen_s(&file,filepath, "rt");
			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);

			char* data = new char[length + 1];

			memset(data, 0, length + 1);

			fseek(file, 0, SEEK_SET);

			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);
			delete[] data;

			return result;
		}

		static std::string GetCurrentWorkingDirectory()
		{
			std::string str;
			char ch[MAX_PATH];


			_getcwd(ch, MAX_PATH);//ok...
			str = ch;
			return str;
		}

		static std::string GetOutputDirectory()
		{
			std::string str = GetCurrentWorkingDirectory();
			str = str + std::string("../Assets/output");
			return str;
		}

		void OpenFile(std::string path);

		std::string GetLine();
	private:
		std::ifstream m_FileIn;
	};
	
}
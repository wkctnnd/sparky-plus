#pragma once
#include <string>
namespace sparky
{
	class Logger
	{
	public:


		Logger(std::string outputpath);
		void Log(std::string text);
	private:
		class File* m_LogFile;
	};


}
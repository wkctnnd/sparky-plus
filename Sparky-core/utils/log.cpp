#include "log.h"
#include "File.h"
#include "fileutils.h"
namespace sparky
{
	Logger::Logger(std::string outputfile)
	{
		std::string path = FileUtile::GetCurrentWorkingDirectory() + std::string("\\..\\Assets\\output\\logfile\\")+ outputfile;
		m_LogFile = new File(path, FileMode::File_Write);
		
	}

	void Logger::Log(std::string text)
	{
		m_LogFile->WriteLine(text);
	}

	//template<typename T, typename ... Types>
	//void Logger::Log(const T& arg1, const Types & ...args)
	//{

	//	//m_LogFile->WriteLine(text);
	//}
}

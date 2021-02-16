#include "log.h"
#include "File.h"
namespace sparky
{
	Logger::Logger(std::string outputpath)
	{
		m_LogFile = new File(outputpath);
		
	}
}

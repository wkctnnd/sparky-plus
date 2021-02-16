#pragma once
#include <string>
namespace sparky
{
	class Logger
	{
	public:


		Logger(std::string outputpath);

	private:
		class File* m_LogFile;
	};


}
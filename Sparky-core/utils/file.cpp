#include "File.h"
#define LINE_LENGTH 100
namespace sparky
{
	void File::OpenFile(std::string path)
	{
		m_FileIn.open(path.c_str());
		m_Invalid = m_FileIn.fail();
	 
	}

	std::string File::GetLine()
	{
		char str[LINE_LENGTH];
		m_FileIn.getline(str, LINE_LENGTH);
		return std::string(str);
	}

	bool File::IsEnd()
	{
		return m_FileIn.eof();
	}
}
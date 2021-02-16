#include "File.h"

#define LINE_LENGTH 100
namespace sparky
{
	void File::OpenFile(std::string path, FileMode mode = File_Read)
	{
		if (mode==File_Read)
		{
			m_FileIn.open(path.c_str());
			m_Valid = !m_FileIn.fail();
		}
		else if (mode == File_Write)
		{
			m_FileOut.open(path.c_str());
			m_Valid = !m_FileOut.fail();
		}
		else
		{
			m_FileInOut.open(path.c_str());
			m_Valid = !m_FileInOut.fail();
		}
		
		
	 
	}
	//https://blog.csdn.net/qq_34097715/article/details/79970860
	void File::WriteLine(std::string line)
	{
		m_FileOut.
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
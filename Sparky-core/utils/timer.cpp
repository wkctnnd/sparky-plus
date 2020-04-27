#include "timer.h"
#include <time.h>
namespace sparky {
		void Timer::Begin()
		{
			m_Start = clock();
		}

		//时间超过2000ms，将重置
		void Timer::Stop()
		{
			m_End = clock();
			m_Elapse = m_End - m_Start;
			if (m_Elapse > 2000)
			{
				m_Elapse = 330;
			}
		}

		unsigned long Timer::GetElapsemillionseconds()
		{
			return m_Elapse;
		}

		float Timer::GetElapseSeconds() const
		{
			return ((float)m_Elapse)/ CLOCKS_PER_SEC;
		}

	 
	
}

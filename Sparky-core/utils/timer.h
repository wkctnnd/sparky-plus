#pragma once
#include <iostream>
#include <string>
namespace sparky {
	class Timer
	{
	public:
		void Begin();
		void Stop();

		unsigned long GetElapsemillionseconds();
		float GetElapseSeconds() const;
		std::string GetCurrentTime() const;
	private:
		long m_Start;
		long m_End;
		long m_Elapse;

		friend std::ostream& operator<<(std::ostream& stream, const Timer& timer)
		{
			float time = timer.GetElapseSeconds();
			stream << "timer: " << time << std::endl;
			return stream;

		}
	};

	
}
#pragma once
#include <iostream>
namespace sparky {
	class Timer
	{
	public:
		void Begin();
		void Stop();

		unsigned int GetElapsemillionseconds();
		float GetElapseSeconds() const;
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
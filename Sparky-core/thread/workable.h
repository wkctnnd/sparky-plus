#pragma once
 
namespace sparky
{
	namespace thread
	{
		class Workable
		{
		public:
			virtual void Working() = 0;
			virtual void GetResult() = 0;
		protected:
			int m_Priority;
		};
	}
}
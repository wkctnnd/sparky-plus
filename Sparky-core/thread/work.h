#pragma once
 
namespace sparky
{
	namespace thread
	{
		class Work
		{
		public:
			virtual void Working() = 0;
		protected:
			int m_Priority;
		};
	}
}
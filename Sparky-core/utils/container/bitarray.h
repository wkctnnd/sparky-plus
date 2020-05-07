#pragma once
#include <vector>

namespace sparky
{
	namespace container
	{
		class BitArray
		{
		public:
			BitArray(int size);
			int GetValue(int pos);
 
			void SetValue(int pos, int value);
		private:

			std::vector<int> m_Element;
		};
	}
}


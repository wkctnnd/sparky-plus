#include "bitarray.h"

namespace sparky
{
	namespace container
	{
		BitArray::BitArray(int size)
		{
			m_Element.resize(size);
		}

		void BitArray::SetValue(int pos, int value)
		{
			m_Element[pos] = value;
		}

		int BitArray::GetValue(int pos)
		{
			return m_Element[pos];
		}
	}
}
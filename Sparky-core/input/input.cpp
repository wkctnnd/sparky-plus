#include "input.h"

namespace sparky
{
	namespace input
	{

		bool Input::m_KeyMapping[KeyNum];

		bool Input::GetKey(KeyCode code)
		{
			return m_KeyMapping[code];
		}


		void Input::SetKey(KeyCode code, bool value)
		{
			m_KeyMapping[code] = value;
		}

		void Input::Reset()
		{
			for (int i=0;i<KeyNum;i++)
			{
				m_KeyMapping[i] = false;
			}
		}
	}
 }
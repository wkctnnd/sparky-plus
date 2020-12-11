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
	}
 }
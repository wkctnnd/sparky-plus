#include "input.h"

namespace sparky
{
	namespace input
	{

		bool InputManager::m_KeyMapping[KeyNum];
		MouseState InputManager::m_MouseState;

		bool InputManager::GetKey(KeyCode code)
		{
			return m_KeyMapping[code];
		}


		void InputManager::SetKey(KeyCode code, bool value)
		{
			m_KeyMapping[code] = value;
		}

		void InputManager::Reset()
		{
			for (int i=0;i<KeyNum;i++)
			{
				m_KeyMapping[i] = false;
			}
			m_MouseState.button = Mouse_Button_None;
			m_MouseState.action = Mouse_Release;
		}

		void InputManager::SetMouseActionState(int button, int action)
		{
			m_MouseState.button = (MouseButton)button;
			m_MouseState.action = (MouseAction)action;

		}

		void InputManager::SetMouseMoveState(int x,int y)
		{
			m_MouseState.x = x;
			m_MouseState.y = y;
		}
	}
 }
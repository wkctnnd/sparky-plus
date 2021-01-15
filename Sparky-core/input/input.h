#pragma once

namespace sparky
{
	namespace input
	{

			enum KeyCode
			{
				UPArrow,
				DownArrow,
				KEY_W,
				KEY_S,
				KEY_A,
				KEY_D,

				KEY_V,
				KeyNum
			};

			enum MouseButton
			{
				Mouse_Button_Left,
				Mouse_Button_Right,


				Mouse_Button_None,
			};

			enum MouseAction 
			{
				Mouse_Release,
				Mouse_Press
			};

			struct MouseState
			{
				MouseButton button;
				MouseAction action;
				int x, y;
			};
		class  InputManager
		{
		public:
			static void Initialize()
			{
				Reset();
			}

			static bool GetKey(KeyCode  code);

			static void Reset();
			static void SetKey(KeyCode  code, bool value);

			static MouseState GetMouseState() { return m_MouseState; }

			static void SetMouseActionState(int button, int action);
			static void SetMouseMoveState(int x, int y);
		protected:
		private:

			static bool m_KeyMapping[KeyNum];
			static MouseState m_MouseState;
		};

		
	}
}

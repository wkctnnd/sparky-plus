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

				KeyNum
			};




		class  Input
		{
		public:

			static bool GetKey(KeyCode  code);

			static void Reset();
			static void SetKey(KeyCode  code, bool value);
		protected:
		private:

			static bool m_KeyMapping[KeyNum];
		};

		
	}
}

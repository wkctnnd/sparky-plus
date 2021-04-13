#include "uimanager.h"

namespace sparky
{
	namespace ui
	{
		void* UIManager::GetNativeWindow()
		{
			return m_NativeWindow;
		}

		class Widget* UIManager::GetWidget()
		{
			return m_Widgets[0];
		}
	}
}
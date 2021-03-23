#include "editor.h"
#include "ui/uimanager.h"
namespace sparky
{
	namespace editor
	{
		void Editor::Init()
		{
			bool res = m_UIManager->Initialize();
		}
	}
}
 
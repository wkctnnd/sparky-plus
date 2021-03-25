#include "layout.h"


namespace sparky
{
	namespace ui
	{


		int Layout::OnMouseClick(int x, int y)
		{
			for (int i=0;i<m_Children.size();i++)
			{
				m_Children[i]->OnMouseClick(x, y);
			}
		}

		int Layout::OnKeyPress(input::KeyCode code)
		{
			for (int i = 0; i < m_Children.size(); i++)
			{
				m_Children[i]->OnKeyPress(code);
			}
		}

		int Layout::OnMouseMove(int x, int y)
		{
			for (int i = 0; i < m_Children.size(); i++)
			{
				m_Children[i]->OnMouseClick(x, y);
			}
		}




	}
}
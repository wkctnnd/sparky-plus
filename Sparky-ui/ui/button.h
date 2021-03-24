#pragma once
#include<string>
#include "widget.h"
namespace sparky
{
	namespace ui
	{
		class Button:public Widget
		{
		public:
			virtual int OnMouseClick(int x, int y) { return 0; };
			virtual int OnKeyPress(input::KeyCode code) { return 0; };
			virtual int OnMouseMove(int x, int y) { return 0; };
		protected:
			std::string m_Name;
			int m_Layer;
		};
	}
}

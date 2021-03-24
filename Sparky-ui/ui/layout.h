#pragma once
#include<string>
#include "widget.h"
#include <vector>
namespace sparky
{
	namespace ui
	{
		class Layout:public Widget
		{
		public:
			virtual void OnInit() = 0;
			virtual void OnActive() = 0;

			virtual void OnBindEvent() = 0;
			virtual void OnUnBindEvent() = 0;
			virtual void OnDeactive() = 0;


			virtual int OnMouseClick(int x, int y);
			virtual int OnKeyPress(input::KeyCode code);
			virtual int OnMouseMove(int x, int y);


	 
		protected:
			 
			std::vector<Widget*> m_Widgets;
		};
	}
}
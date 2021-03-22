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
		protected:
			 
			std::vector<Widget*> m_Widgets;
		};
	}
}
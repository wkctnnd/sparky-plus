#pragma once
#include<string>
#include "uibase.h"
#include "input/input.h"
namespace sparky
{
	namespace ui
	{
		class Widget
		{
		public:
			virtual void OnInit() = 0;
			virtual void OnActive() = 0;

			virtual void OnBindEvent() = 0;
			virtual void OnUnBindEvent() = 0;
			virtual void OnDeactive() = 0;




			virtual int OnMouseClick(int x, int y) { return 0; };
			virtual int OnKeyPress(input::KeyCode code) { return 0; };
			virtual int OnMouseMove(int x, int y) { return 0; };
		protected:
			std::string m_Name;
			int m_Layer;

			
		};
	}
}

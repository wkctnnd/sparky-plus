#pragma once
#include<string>
#include "world/component/component.h"
#include "input/input.h"


using namespace sparky::world;
using namespace sparky::input;

namespace sparky
{
	namespace ui
	{
		enum RenderMode
		{
			ScreenSpace_Overlay,
			ScreenSpace_Camera,
			WorldSpace
		};
		class Canvas :public Component
		{
		public:
	 
			virtual int OnMouseClick(int x, int y) { return 0; };
			virtual int OnKeyPress(input::KeyCode code) { return 0; };
			virtual int OnMouseMove(int x, int y) { return 0; };
		protected:
			std::string m_Name;
			int m_Layer;
			RenderMode m_RenderMode;

			int m_SortId;
		};
	}
}

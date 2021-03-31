#pragma once
#include<string>
#include "world/component/component.h"
#include "input/input.h"
using namespace sparky::world;

namespace sparky
{
	namespace ui
	{
		class Text :public Component
		{
		public:
	 
			virtual int OnMouseClick(int x, int y) { return 0; };
			virtual int OnKeyPress(input::KeyCode code) { return 0; };
			virtual int OnMouseMove(int x, int y) { return 0; };

			void Update();
		protected:
			std::string m_Name;
			int m_Layer;
		};
	}
}

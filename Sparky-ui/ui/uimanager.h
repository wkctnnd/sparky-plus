#pragma once
#include<string>
#include "./global.h"
 
#include <vector>
//https://zhuanlan.zhihu.com/p/264488549
namespace sparky
{
	namespace ui
	{
		class UI_API UIManager
		{
		public:

			 bool Initialize();
			 void ActiveUI();
			 void DeActiveUI();
			 class Widget* GetWidget();
			 void ClearStack();
			 void DeActiveAll();
			 void OnLogin();
			 void OnLogOut();
			 void OnEnterScene();

		protected:
			std::vector<class Widget*> m_Widgets;
			class Window* m_RootWidget;
		};
	}
}
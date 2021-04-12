#pragma once
#include<string>
#include "./global.h"
#include <vector>
#include "ui/uimanager.h"
//https://zhuanlan.zhihu.com/p/264488549

//unity ui
//https://blog.csdn.net/book_longssl/article/details/42398393
namespace sparky
{
	namespace ui
	{
		class UI_API ImguiManager:public UIManager
		{
		public:
			ImguiManager()
			{

			}
			 bool Initialize(void* window);
			 void ActiveUI();
			 void DeActiveUI();

	
			 void Render();
			 void Shutdown();
			 void Begin();
			 void End();

			 void* GetNativeWindow(void);
		public:
			/*void ClearStack();
			void DeActiveAll();
			void OnLogin();
			void OnLogOut();
			void OnEnterScene();
			void* GetNativeWindow();*/
		protected:
 
		};
	}
}
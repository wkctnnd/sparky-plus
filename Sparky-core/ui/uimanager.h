#pragma once
#include<string>
#include "./global.h"
#include <vector>
//https://zhuanlan.zhihu.com/p/264488549

//unity ui
//https://blog.csdn.net/book_longssl/article/details/42398393
namespace sparky
{
	namespace ui
	{
		class  UIManager
		{
		public:

			virtual bool Initialize(void* window) = 0;
			virtual void ActiveUI() = 0;
			virtual void DeActiveUI() =0;


			virtual  void Render() = 0;
			virtual void Shutdown() = 0;
			virtual void Begin() = 0;
			virtual void End() = 0;




			void* GetNativeWindow();
 
 
			class Widget* GetWidget();
			/*virtual void ClearStack() = 0;
			virtual void DeActiveAll() = 0;
			virtual void OnLogin() = 0;
			virtual void OnLogOut() = 0;
			virtual void OnEnterScene() = 0;
			virtual void* GetNativeWindow() = 0;
			virtual void Render() = 0;*/



		protected:
			std::vector<class Widget*> m_Widgets;
			class Window* m_RootWidget;
			void* m_NativeWindow;
		};
	}
}
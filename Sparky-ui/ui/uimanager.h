#pragma once
#include<string>
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
			 class UIBass* GetUI();
			 void ClearStack();
			 void DeActiveAll();
			 void OnLogin();
			 void OnLogOut();
			 void OnEnterScene();

		protected:
			std::string m_Name;
			int m_Layer;
		};
	}
}
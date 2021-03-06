#pragma once
#include<string>
namespace sparky
{
	namespace ui
	{
		class UIBase
		{
		public:
			virtual void OnInit() = 0;
			virtual void OnActive() = 0;

			virtual void OnBindEvent() = 0;
			virtual void OnUnBindEvent() = 0;
			virtual void OnDeactive() = 0;
		protected:
			std::string m_Name;
			int m_Layer;
		};
	}
}
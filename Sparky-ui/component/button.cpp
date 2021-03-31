#include "button.h"
#include "imgui.h"
namespace sparky
{
	namespace ui
	{
		void Button::Update()
		{
			ImGui::Button("Button");
		}
	}
}
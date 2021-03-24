#pragma once

#include "utils/DelegateList.h"
#include "input/input.h"
namespace sparky
{
	namespace core
	{
		//mouseposx,mouseposy
		typedef sparky::DelegateEvent<int(int, int)> MouseMoveEvent;

		//button, mouseposx,mouseposy
		typedef sparky::DelegateEvent<int(input::MouseButton, int, int)> MouseClickEvent;

		//button, mouseposx,mouseposy
		typedef sparky::DelegateEvent<int(int, int, int)> MouseReleaseEvent;

		//mouseposx,mouseposy
		typedef sparky::DelegateEvent<int(input::KeyCode)> KeyPressEvent;
	}

}

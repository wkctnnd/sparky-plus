#pragma once
#include "component.h"
namespace sparky
{
	namespace world
	{
		class ScriptComponent:public Component
		{
		public:
			virtual void PreUpdate() {}
			virtual void Update() {}
			virtual void PostUpdate() {}


			virtual void OnCollided() {};
		};
	}
}
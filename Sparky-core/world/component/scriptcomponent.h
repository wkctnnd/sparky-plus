#pragma once
#include "component.h"
#include "physics/pxShape.h"
namespace sparky
{
	namespace world
	{
		class ScriptComponent :public Component
		{
		public:
			static ComponentType TYPE;
			ComponentType GetType() { return ComponentType::SCRIPT_TYPE; }
			ScriptComponent(Actor* owner) :Component(owner) {}
			virtual void PreUpdate() {}
			virtual void Update() {}
			virtual void PostUpdate() {}


			virtual void OnCollided(std::vector<phyx::HitPointInfo>& hitpointinfos) {};
		};
	}
}
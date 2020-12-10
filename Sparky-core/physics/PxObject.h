#pragma once
#include "maths/vec3.h"
#include <vector>
#include "world/component/scriptcomponent.h"
#include "pxShape.h"
using namespace sparky::maths;
namespace sparky
{
	namespace world
	{
		class ScriptComponent;
	}
	namespace phyx
	{
		class Mass;
		class Spring;
		enum PxObjectType
		{
			SOFT_BODY,
			RIGID_BODY
		};

		struct Force
		{
			float3 position;
			float3 force;
		};
		class PxObject
		{
		public:
			PxObject(world::ScriptComponent* sc) :m_ScriptComponent(sc) {}
			virtual PxObjectType GetType() = 0;
			virtual void ApplyForce(std::vector<Force>& force) = 0;
			virtual void Simulate(float time) = 0;
			virtual void Update(float time) = 0;
			world::Actor* GetActor() { return m_ScriptComponent->GetOwner(); }
			virtual bool CollideWith(PxObject* object, HitResult& result) {
				return false;
			}

			void Notify()
			{
				m_ScriptComponent->OnCollided();
			}
			//virtual void GetRenderData() = 0;
		private:
 

		protected:
			world::ScriptComponent* m_ScriptComponent;
		};
	}
}

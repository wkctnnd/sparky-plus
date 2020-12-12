#pragma once
#include "maths/vec3.h"
#include <vector>
#include "world/component/scriptcomponent.h"
#include "pxShape.h"
#include "maths/mat4.h"
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
			PxObject(world::ScriptComponent* sc, phyx::PxShape* shape, mat4 matp);
			virtual PxObjectType GetType() = 0;
			virtual void ApplyForce(std::vector<Force>& force) {}
			virtual void Simulate(float time) {}
			virtual void Update(float time) {}
			world::Actor* GetActor() { return m_ScriptComponent->GetOwner(); }
			virtual bool CollideWith(PxObject* object, HitResult& result) {
				return false;
			}
			void SetShape(phyx::PxShape* shape, mat4 mat)
			{

			}
			phyx::PxShape* GetShape() { return m_Shape; }
			void Notify()
			{
				m_ScriptComponent->OnCollided();
			}
			void SetWorldMatrix(mat4 mat)
			{
				m_WorldMat = mat;
			}
			//virtual void GetRenderData() = 0;
		private:
 

		protected:
			class phyx::PxShape *m_Shape;
			world::ScriptComponent* m_ScriptComponent;
			mat4 m_WorldMat;
		};
	}
}

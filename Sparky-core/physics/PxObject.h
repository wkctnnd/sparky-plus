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
			PxObject(world::Actor* sc=0, phyx::PxShape* shape =0, mat4* matp=0);
			virtual PxObjectType GetType() = 0;
			virtual void ApplyForce(std::vector<Force>& force) {}
			virtual void Simulate(float time) {}
			virtual void Update(float time) {}
			world::Actor* GetActor() { return m_Owner; }
			virtual bool CollideWith(PxObject* object, HitResult& result) {
				return false;
			}
			void SetShape(phyx::PxShape* shape, mat4 mat)
			{

			}
			phyx::PxShape* GetShape() { return m_Shape; }
			void Notify(std::vector<HitPointInfo>& hitinfos)
			{
				if (m_ScriptComponent)
				{
					m_ScriptComponent->OnCollided(hitinfos);
				}
				
			}
			void SetWorldMatrix(mat4 mat)
			{
				m_WorldMat = mat;
			}

			world::ScriptComponent* GetScriptComponent() { return m_ScriptComponent; }
			//virtual void GetRenderData() = 0;
		private:
 

		protected:
			class phyx::PxShape *m_Shape;
			world::ScriptComponent* m_ScriptComponent;
			world::Actor* m_Owner;
			mat4 m_WorldMat;
		};
	}
}

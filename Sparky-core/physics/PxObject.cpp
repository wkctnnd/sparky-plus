#include "PxObject.h"
#include "world/actor.h"
#include "world/component/scriptcomponent.h"
namespace sparky
{
	namespace phyx
	{
		PxObject::PxObject(world::Actor* sc, phyx::PxShape* shape, mat4* matp) :m_Owner(sc)
		{
			m_Shape = shape->NewShapeFromMatrix(*matp);
			if (m_Owner)
			{
				m_ScriptComponent = (world::ScriptComponent*)m_Owner->GetComponent<world::ScriptComponent>();
			}
		}
	}
}
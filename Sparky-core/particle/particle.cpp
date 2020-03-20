#include "particle.h"

namespace sparky
{
	namespace particle
	{
		void Particle::Reset()
		{
			m_Speed.x = m_Speed.y = m_Speed.z = 0;
			m_Life = 0;
			m_Duration = 0;
			m_Color.x = m_Color.y = m_Color.z = 0;
			m_Scale.x = m_Scale.y = m_Scale.z = 0.1;
			m_position.x = m_position.y = m_position.z = 0;
		}
	}
}
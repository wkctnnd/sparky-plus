#include "physics/PxWorld.h"
#include "physics/PxObject.h"

namespace sparky
{
	namespace phyx
	{
		void PxWorld::AddObject(PxObject* object)
		{
			m_Objects.push_back(object);
		}

		void PxWorld::Simulate(float time)
		{
			for (int i=0;i<m_Objects.size();i++)
			{
				m_Objects[i]->Simulate(time);
			}
		}

		void PxWorld::Update(float time)
		{
			for (int i = 0; i < m_Objects.size(); i++)
			{
				m_Objects[i]->Update(time);
			}






		}

		void PxWorld::FetchResult(std::vector<PxObject *> &objects)
		{
			for (int i=0;i<m_Objects.size();i++)
			{
				objects.push_back(m_Objects[i]);
			}
		}
	}
}
#include "physics/PxWorld.h"
#include "physics/PxObject.h"
#include "physics/CollisionHelper.h"
#include "world/component/scriptcomponent.h"
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



			for (int i=0;i<m_Objects.size();i++)
			{
				if (m_Objects[i]->GetType() == RIGID_BODY)
				{
					HitResult result;
					for (int j = 0; j < m_Objects.size(); j++)
					{
						if (i!=j)
						{
							if (m_Objects[i]->CollideWith(m_Objects[j], result))
							{
								result.AddHitPointInfo(float3(0, 0, 0), float3(0, 0, 0), m_Objects[j]->GetActor());
							}
						}
						m_NotifyObjects.push_back(result);
					}
				}
				
			}


		}

		void PxWorld::FetchResult(std::vector<PxObject *> &objects)
		{
			for (int i=0;i<m_Objects.size();i++)
			{
				objects.push_back(m_Objects[i]);
			}
		}

		void PxWorld::Notify()
		{
			for (int i=0;i<m_Objects.size();i++)
			{
				if (m_NotifyObjects[i].IsCollided())
				{
					m_Objects[i]->Notify();
				}
			}
		}
	}
}
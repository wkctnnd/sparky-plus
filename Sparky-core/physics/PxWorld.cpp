#include "physics/PxWorld.h"
#include "physics/PxObject.h"
#include "physics/CollisionHelper.h"
#include "world/component/scriptcomponent.h"
#include "world/scene.h"
#include "world/actor.h"
#include "world/component/rigidbodycomponent.h"
#include "physics/PxRigidBody.h"
using namespace sparky::world;
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
					/*			if (m_Objects[j]->GetScriptComponent()==0)
								{
									result.AddHitPointInfo(float3(0, 0, 0), float3(0, 0, 0), 0);
								}
								else*/
									result.AddHitPointInfo(float3(0, 0, 0), float3(0, 0, 0), m_Objects[j]->GetActor());
							}
						}
						
					}
					m_NotifyObjects.push_back(result);
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
					m_Objects[i]->Notify(m_NotifyObjects[i].GetHitPointInfos());
				}
			}
		}

		void PxWorld::AddObjects(world::Scene* scene)
		{
			Reset();
			std::vector<RigidBodyComponent*> comps = scene->GetRoot()->GetChildrenComponents<RigidBodyComponent>();
			/*for (int i = 0; i < comps.size(); i++)
			{
				Renderable* r = comps[i]->GetRenderable();
				PhotoObjects.push_back(r);
			}*/

			for (int i = 0; i < comps.size(); i++)
			{
				if (comps[i]->IsEnable())
				{
					PxRigidBody* rigidbody = (PxRigidBody*)comps[i]->GetRigidBody();
					if (rigidbody)
					{
						AddObject(rigidbody);
					}
				}
				

			}


		}

		void PxWorld::Reset()
		{
			m_Objects.clear();
			m_NotifyObjects.clear();
		}
	}
}
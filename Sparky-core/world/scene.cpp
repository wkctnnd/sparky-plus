#include "scene.h"
#include "actor.h"
namespace sparky
{
	namespace world
	{
		void Scene::Initialize() 
		{
			GScene = this;
			m_RootActor = new Actor();
		}

		void Scene::AddActor(Actor* atr)
		{
			m_RootActor->Attach(atr);
			 
		}

		Actor * Scene::AddActor()
		{
			Actor *atr = new Actor();
			m_RootActor->Attach(atr);
			return atr;
		}

		void Scene::Update(float t)
		{
			for (int i=0;i<m_AllActors.size();i++)
			{
			
			}
		}

		void Scene::UpdateTransform()
		{
			m_RootActor->GetTransform()->UpdateChain();
		}
	}
}
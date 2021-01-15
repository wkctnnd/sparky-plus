#include "scene.h"
#include "actor.h"
#include "world/lightsceneproxy.h"
#include "world/component/cameracomponent.h"
namespace sparky
{
	namespace world
	{
		void Scene::Initialize() 
		{
			GScene = this;
			m_RootActor = new Actor();
			m_AllActors.push_back(m_RootActor);
		}

		void Scene::AddActor(Actor* atr, Actor* parent)
		{
			if (parent == 0)
			{
				m_RootActor->Attach(atr);
			}
			else
				parent->Attach(atr);
			m_AllActors.push_back(atr);
		}
 

		Actor * Scene::AddActor()
		{
			Actor *atr = new Actor();
			m_RootActor->Attach(atr);
			m_AllActors.push_back(atr);
			return atr;
		}

		void Scene::Update(float t)
		{
			for (int i=0;i<m_AllActors.size();i++)
			{
				m_AllActors[i]->Update();
			}
		}

		void Scene::UpdateTransform()
		{
			m_RootActor->GetTransform()->UpdateChain();
		}

		int Scene::GetLightNum()
		{
			return m_Lights.size();
		}


		LightSceneProxy* Scene::GetLight(int id)
		{
			return m_Lights[id];
		}

		class CameraComponent* Scene::GetCameraMain()
		{
			class CameraComponent* camera = (CameraComponent*)(m_RootActor->GetChildrenComponents<CameraComponent>()[0]);
			return camera;
		}
	}
}
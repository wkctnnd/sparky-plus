#pragma once
#include <vector>
namespace sparky
{
	namespace render
	{
		class SceneRenderer;
	}
}

namespace sparky
{
	namespace world
	{
		class TransformComponent;
		class Actor;
		class Scene
		{
		public:
			void Initialize();
			void AddActor(Actor* atr, Actor* parent= 0);
			Actor* AddActor(); 
			void Update(float t);

			render::SceneRenderer* GetRenderer() { return m_SceneRenderer; }
			Actor* GetRoot() { return m_RootActor; }
			static Scene* GetCurrentScene() { return m_CurrentScene; };
			void UpdateTransform();
			int GetLightNum();
			class LightSceneProxy* GetLight(int id);

			class CameraComponent* GetCameraMain();
		private:

			static Scene* m_CurrentScene;
			std::vector<Actor*> m_AllActors;
			std::vector<LightSceneProxy*> m_Lights;
			Actor* m_RootActor;
			render::SceneRenderer* m_SceneRenderer;
		};

		static Scene* GScene;
	}
}
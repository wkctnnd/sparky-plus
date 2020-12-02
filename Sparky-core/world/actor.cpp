#include "actor.h"
#include "scene.h"
#include "component/transformcomponent.h"
#include "render/renderpath/SceneRenderer.h"

namespace sparky
{
	namespace render
	{
		class StaticMeshRendererComponent;
	}
	namespace world
	{
		void Actor::Attach(Actor* actor)
		{
			TransformComponent* trans = (TransformComponent*)m_Components[0];
			TransformComponent* trans2 = (TransformComponent*)actor->GetComponent(0);
			trans->AttachTo(*trans2);

		}

		Actor::Actor()
		{
			m_Components.push_back(new TransformComponent());
		}

		void Actor::AddToScene(Scene* scene)
		{
			//将可渲染组件放入scene中，最后放入renderer渲染
			render::StaticMeshRendererComponent *comp = GetComponent<render::StaticMeshRendererComponent>();
			render::SceneRenderer* renderer = scene->GetRenderer();
			renderer->
		}
	}
}
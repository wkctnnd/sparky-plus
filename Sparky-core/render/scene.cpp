#pragma once
#include "scene.h"
#include <vector>
namespace sparky
{
	namespace render
	{
		void Scene::AddSceneProxy(class SceneProxy* proxy)
		{
			m_SceneProxyArray.push_back(proxy);
		}
	}
}
#pragma once
#include "maths/vec3.h"
#include <vector>
#include "utils/container/bitarray.h"
using namespace sparky::maths;
using namespace sparky::container;
//用于视口渲染，可以根据当前相机位置裁剪获得可视列表，更新相机有关的uniformbuffer


class View
{
public:
	//void 
	void UpdateViewUniformBuffer();
	void AddSceneProxy(class PrimitiveSceneProxy* sceneporxy);

	void UpdateVisibleSet();
private:

	
	float3 m_ViewLocation;
	float3 m_ViewForwrd;
	float3 m_ViewRight;

	std::vector<class PrimitiveSceneProxy*> m_SceneProxyArray;
	BitArray  m_VisibleArray;

};
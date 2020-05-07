#pragma once
#include "maths/vec3.h"
#include <vector>
#include "utils/container/bitarray.h"
using namespace sparky::maths;
using namespace sparky::container;
//�����ӿ���Ⱦ�����Ը��ݵ�ǰ���λ�òü���ÿ����б���������йص�uniformbuffer


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
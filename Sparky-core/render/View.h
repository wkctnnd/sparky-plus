#pragma once
#include "maths/vec3.h"
using namespace sparky::maths;

//用于视口渲染，可以根据当前相机位置裁剪获得可视列表，更新相机有关的uniformbuffer
class View
{
public:
	//void 
	void UpdateViewUniformBuffer();
	
private:

	
	float3 m_ViewLocation;
	float3 m_ViewForwrd;
	float3 m_ViewRight;

	

};
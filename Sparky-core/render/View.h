#pragma once
#include "maths/vec3.h"
using namespace sparky::maths;

//�����ӿ���Ⱦ�����Ը��ݵ�ǰ���λ�òü���ÿ����б���������йص�uniformbuffer
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
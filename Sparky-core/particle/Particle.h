#pragma once

#include <vector>
#include "render/renderable.h"
#include "maths/vec3.h"
using namespace sparky::render;
using namespace sparky::maths;
namespace sparky
{
	namespace particle
	{
		struct Particle
		{
	 
			Particle()
			{
				Reset();
			}

			void Reset();
	 
			float3 m_Speed;
			float m_Life;
			float m_Duration;
			float3 m_Color;
			float3 m_Scale;

			float3 m_position;
		};



	}
}

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
	 
			vec3 m_Speed;
			float m_Life;
			float m_Duration;
			vec3 m_Color;
			vec3 m_Scale;

			vec3 m_position;
		};



	}
}

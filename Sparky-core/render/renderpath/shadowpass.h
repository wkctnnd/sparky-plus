#pragma once
#include "pass.h"
namespace sparky
{
	namespace render
	{
		class ShadowPass:public Pass
		{
		public:
			void AddMeshDrawCommand(world::PrimitiveSceneProxy* psp, world::Scene* lightproxy);
			void Process();


		};
	}
}
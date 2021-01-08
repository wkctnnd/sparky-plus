#pragma once
#include "pass.h"
namespace sparky
{
	namespace render
	{
		class LightPass :public Pass
		{
		public:
			void AddMeshDrawCommand();
			void Process();
		};
	}
}

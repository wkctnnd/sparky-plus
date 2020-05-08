#pragma once
#include <string>

namespace sparky
{
	namespace ecs
	{
		class World
		{
		public:
			class IComponent*  GetComponent(std::string name);
		private:
			
		};
	}
}
#pragma once
#include <vector>
namespace sparky
{
	namespace ecs
	{
		class Entity
		{


		protected:
			unsigned int m_EntityId;

			std::vector<unsigned int>  m_ComponentArray;

			template<class T>
			std::vector<T> m_
		};
	}
}
#pragma once
#include <vector>
namespace sparky
{
	namespace phyx
	{
		class PxObject;
		class PxWorld
		{
		public:
			void Simulate(float time);
			void FetchResult();

		private:

			std::vector<PxObject*> m_Objects;
		};
	}
}

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
			void FetchResult(std::vector<PxObject*>& objects);
			void AddObject(PxObject* object);
		private:

			std::vector<PxObject*> m_Objects;
		};
	}
}

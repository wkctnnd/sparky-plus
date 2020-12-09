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
			void Update(float time);
			void Simulate(float time);
			void FetchResult(std::vector<PxObject*>& objects);
			void AddObject(PxObject* object);


			void Notify();
		private:

			std::vector<PxObject*> m_Objects;
		};
	}
}

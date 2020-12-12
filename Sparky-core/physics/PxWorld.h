#pragma once
#include <vector>
#include "physics/pxShape.h"
namespace sparky
{
	namespace world
	{
		class Scene;
	}
	namespace phyx
	{

		struct NotifyInfo
		{
			int id;
			HitResult result;
		};
		class PxObject;
		class PxWorld
		{
		public:
			void Update(float time);
			void Simulate(float time);
			void FetchResult(std::vector<PxObject*>& objects);
			void AddObject(PxObject* object);

			void AddObjects(world::Scene* scene);
			void Notify();

			void Reset();
		private:

			std::vector<HitResult> m_NotifyObjects;
			std::vector<PxObject*> m_Objects;
		};
	}
}

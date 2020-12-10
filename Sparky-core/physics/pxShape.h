#pragma once
 
#include "maths/vec3.h"
#include <vector>
#include "maths/AABox.h"
 

namespace sparky
{

	namespace world
	{
		class Actor;
	}
	namespace phyx
	{
		enum ShapeType
		{
			Shere_Shape,
			AABB_Shape,
			OBB_Shadpe,
		};

		struct HitPointInfo
		{
			float3 Position;
			float3 Normal;
			world::Actor* Actor;
			 
		};
		class HitResult
		{
		public:
			void AddHitPointInfo(float3 position, float3 normal, world::Actor* actor)
			{
				m_HitPointInfo.emplace_back(position, normal, actor);
			}
			bool IsCollided() {
				return m_HitPointInfo.size() > 0;
			}
		private:
			std::vector<HitPointInfo> m_HitPointInfo;
			 
			
		};


		class PxShape  
		{
		public:
			 
			ShapeType GetType() { return m_ShapeType; }

			virtual bool Collide(PxShape* shape, HitResult& result) = 0;
 
		protected:

			ShapeType m_ShapeType;
			 

			//void *UpdateDelegate(int);
		};
	}
}
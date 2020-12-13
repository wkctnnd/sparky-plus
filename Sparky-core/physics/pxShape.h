#pragma once
 
#include "maths/vec3.h"
#include <vector>
#include "maths/AABox.h"

using namespace sparky::maths;
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
			Sphere_Shape,
			AABB_Shape,
			OBB_Shadpe,
		};

	struct HitPointInfo
		{
			HitPointInfo(float3 p, float3 n, world::Actor* actor)
			{
				Position = p;
				Normal = n;
				Actor = actor;
			}
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
			
			virtual PxShape* NewShapeFromMatrix(maths::mat4& mat) = 0;
		protected:

			ShapeType m_ShapeType;
			 

			//void *UpdateDelegate(int);
		};
	}
}
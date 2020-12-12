#pragma once

#include "maths/vec3.h"
#include <vector>
#include "maths/sphere.h"
#include "pxShape.h"
#include "Asset/rawmesh.h"

using namespace sparky::maths;
namespace sparky
{
	namespace asset
	{
		class RawMesh;
	}
	namespace phyx
	{

		class PxShpereShape :public PxShape
		{
		public:
			virtual bool Collide(PxShape* othershape, HitResult& result);
			PxShpereShape(asset::RawMesh* mesh);

		protected:

			 sparky::maths::Shpere m_Sphere;
			//void *UpdateDelegate(int);
		};



	}
}
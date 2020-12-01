#pragma once
#include "maths/vec3.h"
#include "component.h"
#include "maths/quaternion.h"
#include "maths/mat4.h"
#include "render/mesh.h"
#include "render/material.h"
#include "Asset/rawmesh.h"
using namespace sparky::maths;
using namespace sparky::render;
using namespace sparky::asset;
namespace sparky
{
	namespace world
	{
		class Actor;

		class Truck
		{
			RawMesh *staticmesh;
			int materialid;
		};

		//Lod material mesh
		class StaticMeshRendererComponent :public Component
		{
		public:

			static ComponentType TYPE;

			void AddStaticMesh(RawMesh* mesh);
			void SetMaterial(int index, Material& mat);
			Mesh GetRenderable();
			void PostUpdate();
			ComponentType GetType()
			{
				return ComponentType::STATICMESHRENDERER_TYPE;
			}
		private:
		 
			std::vector<Truck> m_Trunks;
			std::vector<Material> m_Materials;
			bool m_Dirty;

		};


	}
}


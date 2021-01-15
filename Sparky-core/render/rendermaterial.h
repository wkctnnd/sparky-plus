#pragma once
#include "maths/vec3.h"
using namespace sparky::maths;
namespace sparky
{
	namespace graphics
	{
		class Texture;
	}
	namespace asset
	{
		class Material;
	}
	namespace render
	{
		class RenderMaterial
		{
		public:

			static RenderMaterial* CreateMaterial(asset::Material* asset);

			static RenderMaterial* CreateDefaultMaterial();
			RenderMaterial() { m_Diffuse.x = 1; m_Diffuse.y = 1; m_Diffuse.z = 1; };
			void SetToonActive(bool enable)
			{
				m_IsToon = enable;
			}
			graphics::Texture* GetDiffuseMap()
			{
				return m_DiffuseMap;
			}

			graphics::Texture* GetNormalMap()
			{
				return m_NormalMap;
			}

			void SetDiffuseMap(graphics::Texture* texture)
			{
				m_DiffuseMap = texture;
			}

			void SetNormalMap(graphics::Texture* texture)
			{
				m_NormalMap = texture;
			}

			void SetDiffuseColor(float3 color)
			{

				m_Diffuse = color;
			}

			float3 GetDiffuseColor()
			{
				return m_Diffuse;

			}
			bool IsToon()
			{
				return m_IsToon;
			}
		private:
			float3 m_Ambient;
			float3 m_Specular;
			float3 m_Diffuse;

			graphics::Texture* m_DiffuseMap;
			graphics::Texture* m_NormalMap;
			bool m_IsToon;
		};
	}
}
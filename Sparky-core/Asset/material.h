#pragma once
#include "maths/vec3.h"
#include "asset.h"
using namespace sparky::maths;
namespace sparky
{
	namespace graphics
	{
		class Texture;
	}
	namespace asset
	{
		class Material :public Asset
		{
		public:
			Material():Asset(Material_Type)
			{

			}
			void SetAmbientColor(float r, float g, float b)
			{
				m_Ambient.x = r;
				m_Ambient.y = g;
				m_Ambient.z = b;
			}

			void SetDiffuseColor(float r, float g, float b)
			{
				m_Diffuse.x = r;
				m_Diffuse.y = g;
				m_Diffuse.z = b;
			}


			void SetSpecularColor(float r, float g, float b)
			{
				m_Specular.x = r;
				m_Specular.y = g;
				m_Specular.z = b;
			}


			void SetDiffuseMap(graphics::Texture* map)
			{
				m_DiffuseMap = map;
			}

			void SetNormalMap(graphics::Texture* map)
			{
				m_NormalMap = map;
			}

			graphics::Texture* GetDiffuseMap()
			{
				return m_DiffuseMap;
			}

			graphics::Texture* GetNormalMap()
			{
				return m_NormalMap;
			}
		private:
			float3 m_Ambient;
			float3 m_Specular;
			float3 m_Diffuse;

			graphics::Texture* m_DiffuseMap;
			graphics::Texture* m_NormalMap;
		};
	}
}
#pragma once
namespace sparky
{
	namespace graphics
	{
		class Texture;
	}
	namespace asset
	{
		class Material
		{
		public:

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
		private:
			float3 m_Ambient;
			float3 m_Specular;
			float3 m_Diffuse;

			graphics::Texture* m_DiffuseMap;
		};
	}
}
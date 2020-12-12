#include "rendermaterial.h"
#include "asset/material.h"

using namespace sparky::asset;
namespace sparky
{
	namespace render
	{

		RenderMaterial*  RenderMaterial::CreateMaterial(asset::Material* asset)
		{
			RenderMaterial* mat = new RenderMaterial();
			mat->m_DiffuseMap = asset->GetDiffuseMap();
			mat->SetToonActive(false);
			return mat;
		}

		RenderMaterial* RenderMaterial::CreateDefaultMaterial()
		{
			RenderMaterial* mat = new RenderMaterial();
			mat->SetToonActive(true);
			return mat;
		}

		

	}
}
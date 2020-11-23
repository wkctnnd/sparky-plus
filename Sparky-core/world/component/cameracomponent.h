#pragma once
#include "component.h"
#include "maths/mat4.h"
using namespace sparky::maths;
namespace sparky
{

	namespace graphics
	{
		class ColorRenderTarget;
		class DepthStencilRenderTarget;
		class RenderTargetInfo;
	}
	namespace world
	{
		class CameraComponent :public Component
		{
		public:
			static ComponentType TYPE;
			mat4 GetProjectionMatrix();
			mat4 GetViewMatrix();
			ComponentType GetType()
			{
				return ComponentType::CAMER_TYPE;
			}
			graphics::RenderTexture* GetColorRenderTexture(int index)
			{
				return m_RtInfo->GetColorRenderTexture(index);
			}
			void SetRenderTarget(std::vector<graphics::ColorRenderTarget*> crt, graphics::DepthStencilRenderTarget* dsrt);
		private:
			float m_Fov;
			float m_Aspect;
			float m_Width;

			float m_Far;

			graphics::RenderTargetInfo* m_RtInfo;
		};

		ComponentType CameraComponent::TYPE = ComponentType::CAMER_TYPE;
	}
}

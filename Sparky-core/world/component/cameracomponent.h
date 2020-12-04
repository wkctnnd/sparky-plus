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
		class RenderTexture;
	}
	namespace world
	{
		class CameraComponent :public Component
		{
		public:
			static ComponentType TYPE;
			CameraComponent(Actor *owner);
			mat4 GetProjectionMatrix();
			mat4 GetViewMatrix();
			virtual void PreUpdate(){}
			virtual void Update() {}
			virtual void PostUpdate() {}
			ComponentType GetType()
			{
				return ComponentType::CAMER_TYPE;
			}
			graphics::RenderTexture* GetColorRenderTexture(int index);
			graphics::RenderTexture* GetDepthStencilRenderTexture();
			//temp use for simple
			graphics::RenderTargetInfo* GetRenderTargetInfo() { return m_RtInfo; }
			void SetRenderTarget(std::vector<graphics::ColorRenderTarget*> crt, graphics::DepthStencilRenderTarget* dsrt);
			//RenderTexture* GetRenderTexture(int index);
		private:
			float m_Fov;
			float m_Aspect;
			float m_Width;

			float m_Far;

			graphics::RenderTargetInfo* m_RtInfo;
		};

		
	}
}

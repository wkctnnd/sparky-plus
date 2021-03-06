#pragma once
#include "cameracomponent.h"
#include "graphics/rendertarget.h"
#include "world/actor.h"
#include "transformcomponent.h"
#include "graphics/texture/rendertexture.h"
#include "graphics/rendertarget.h"
#include "render/View.h"
using namespace sparky::graphics;
using namespace sparky::render;
namespace sparky
{
	namespace world
	{
		ComponentType CameraComponent::TYPE = ComponentType::CAMER_TYPE;

		mat4 CameraComponent::GetViewMatrix()
		{
			mat4 result = m_Owner->GetTransform()->GetWorldTransform().Inverse();
			return result;
		}

		CameraComponent::CameraComponent(Actor *owner):Component(owner)
		{
			m_RtInfo = new graphics::RenderTargetInfo();
		}
		mat4 CameraComponent::GetProjectionMatrix()
		{
			TransformComponent* tc = m_Owner->GetTransform();
			float3 camerforward = tc->Forward();
			float3 destination = tc->GetWorldPosition() + camerforward * m_Far;
			return mat4::LookAt(tc->GetWorldPosition(), destination, tc->Up());
		}

		void CameraComponent::SetRenderTarget(std::vector<graphics::ColorRenderTarget *> crt, graphics::DepthStencilRenderTarget* dsrt)
		{
	 
			for (int i = 0; i < crt.size(); i++)
			{
				if (crt[0] == 0)
				{
					m_RtInfo->SetColorRenderTarget(0, 0);
					break;
				}
				m_RtInfo->SetColorRenderTarget(i, crt[i]);
			}

			m_RtInfo->SetDepthRenderTarget(dsrt);
			
		}

		RenderTexture* CameraComponent::GetColorRenderTexture(int index)
		{
			return m_RtInfo->GetColorRenderTexture(index);
		}

		RenderTexture* CameraComponent::GetDepthStencilRenderTexture()
		{
			return m_RtInfo->GetDepthStencilRenderTexture();
		}

		View* CameraComponent::CreateView()
		{
			View* view = new View();

			return view;
		}
	}
}

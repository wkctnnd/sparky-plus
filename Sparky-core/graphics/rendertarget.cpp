#include "rendertarget.h"
#include "texture/rendertexture.h"

namespace sparky
{
	namespace graphics
	{
		RenderTargetInfo::RenderTargetInfo()
		{
			glGenFramebuffers(1, &m_FrameBufferId);
		}


		void RenderTargetInfo::SetColorRenderTarget(int index, ColorRenderTarget* crt)
		{
			m_ColorTargets[index] = *crt;
		}

		void RenderTargetInfo::SetDepthRenderTarget(DepthStencilRenderTarget* dsrt)
		{
			m_DepthStencilTarget = *dsrt;
		}

		void RenderTargetInfo::Bind()
		{
			if (m_ColorTargets[0].texture == 0)
				glBindFramebuffer(GL_FRAMEBUFFER, 0);
			else
			{
				glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBufferId);
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorTargets[0].texture->GetTexture()->GetRealId(), 0);
				if (m_DepthStencilTarget.texture != 0)
				{
					glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, m_DepthStencilTarget.texture->GetTexture()->GetRealId(), 0);
				}
			}
				//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, 0,)
		}

		void RenderTargetInfo::UnBind()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}
	}
}
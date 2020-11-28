#pragma once
#define MAXMRTNUM 5
#include <gl/glew.h>
namespace sparky
{
	namespace graphics
	{
		class RenderTexture;

		enum ColorRenderTargetAction
		{
			Load_Store,
			DontLoad_DontStore,
			Clear_DontStore,
			Clear_Store
		};


		enum DepthStencilRenderTargetAction
		{
			DepthClearDontStore_StecilClearDontStore,
	 
		};

	 
		class ColorRenderTarget
		{
		public:
			RenderTexture *texture;
			ColorRenderTargetAction action;
			int slice;
			int mipmap;
		};

		class DepthStencilRenderTarget
		{
		public:
			RenderTexture* texture;
			DepthStencilRenderTargetAction action;
		};
		class RenderTargetInfo
		{
		public:
			RenderTargetInfo();
			void SetColorRenderTarget(int index, ColorRenderTarget* crt);
			void SetDepthRenderTarget(DepthStencilRenderTarget* dsrt);

			//temp use
			void Bind();
			void UnBind();
			RenderTexture* GetColorRenderTexture(int index)
			{
				return m_ColorTargets[index].texture;
			}
		private:
			ColorRenderTarget  m_ColorTargets[MAXMRTNUM];
			DepthStencilRenderTarget m_DepthStencilTarget;

			GLuint m_FrameBufferId;
		};
	}
}
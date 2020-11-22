#pragma once
#define MAXMRTNUM 5
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
			void SetColorRenderTarget(int index, ColorRenderTarget* crt);
			void SetDepthRenderTarget(DepthStencilRenderTarget* dsrt);
		private:
			ColorRenderTarget  m_ColorTargets[MAXMRTNUM];
			DepthStencilRenderTarget m_DepthStencilTarget;

		};
	}
}
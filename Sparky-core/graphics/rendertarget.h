#pragma once
#define MAXMRTNUM 5
namespace sparky
{
	namespace graphics
	{
		class RenderTexture;

		enum RenderTargetAction
		{
			Load_Store,
			DontLoad_DontStore,
			Clear_DontStore
		};

		enum DepthStencilTargetAction
		{

		};

		class ColorRenderTarget
		{
			RenderTexture *texture;
			RenderTargetAction action;
			int slice;
			int mipmap;
		};

		class DepthStencilRenderTarget
		{
			RenderTexture* texture;
			RenderTargetAction action;
		};
		class RenderTargetInfo
		{
		public:

		private:
			ColorRenderTarget  m_ColorTargets[MAXMRTNUM];
			DepthStencilRenderTarget m_DepthStencilTarget;

		};
	}
}
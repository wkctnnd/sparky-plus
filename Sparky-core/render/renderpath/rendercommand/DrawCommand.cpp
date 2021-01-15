#include "DrawCommand.h"
#include "render/renderable.h"
#include "graphics/graphicpiplinestate.h"
namespace sparky
{
	namespace render
	{
		std::vector<class DrawCommmand*> DrawCommmand::m_CommandList;

		void DrawCommmand::Execute()
		{

			m_Gps->Bind(m_ShaderBinding);
			m_Renderable->render();
		}
	}
}
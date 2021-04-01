#include "application.h"

#include "graphics/window.h"
#include "maths/vec2.h"
#include "utils/fileutils.h"
#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/computeshader.h"
#include "render/FluidRenderer.h"
#include "render/mesh.h"
#include "utils/timer.h"
#include "engine.h"
#include "window.h"


namespace sparky
{
	void Application::Initialize()
	{
		m_Engine = new Engine();
		m_Window = new Window("Sparky!", 1920, 1080)
	}
}
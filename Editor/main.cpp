
#include <iostream>
#include "graphics/window.h"
#include "maths/vec2.h"
#include "utils/fileutils.h"
#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/computeshader.h"
#include "render/FluidRenderer.h"
#include "render/mesh.h"
#include "utils/timer.h"
#include "engine.h"

#include "input/input.h"
#include "application.h"
using namespace sparky::input;
int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace maths;

	using namespace sparky::render;
	//Window window("Sparky!", 1920, 1080);

	//float2 vector(1.0, 2.0);
	Application* app = Application::Get();



	app->Initialize();
	app->Run();
	/*std::string file = FileUtile::read_file("main.cpp");
	std::cout << file << std::endl;*/

	/*GraphicsShader gshader("shaders/basic.vert","shaders/basic.frag");
	ComputeShader cshader("shaders/test.comp");*/

	//Engine engine;
	//engine.Initialize();
	/*FluidRenderer::FluidParam param;
	FluidRenderer render(param);
	render.Initialize();
	Mesh* smokemesh = Mesh::Load("autoload");
	render.AddSmokeVolume(smokemesh);*/



	system("PAUSE");
	return 0;

}
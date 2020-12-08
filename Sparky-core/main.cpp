
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

int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace maths;
 
	using namespace sparky::render;
	Window window("Sparky!", 800, 600);
	 
	float2 vector(1.0, 2.0);

	/*std::string file = FileUtile::read_file("main.cpp");
	std::cout << file << std::endl;*/

	/*GraphicsShader gshader("shaders/basic.vert","shaders/basic.frag");
	ComputeShader cshader("shaders/test.comp");*/

	Engine engine;
	engine.Initialize();
	/*FluidRenderer::FluidParam param;
	FluidRenderer render(param);
	render.Initialize();
	Mesh* smokemesh = Mesh::Load("autoload");
	render.AddSmokeVolume(smokemesh);*/

	while (!window.Closed())
	{
		glClearColor(1, 1, 1, 1);
		window.clear();
		//std::cout << window.getHeight() << "," << window.getWidth()<<std::endl;
		//std::cout << vector;
		if (window.isKeyPress(GLFW_KEY_W))
		{
			Input.SetKey(KEY_W)
		}

		else if (window.isKeyPress(GLFW_KEY_A))
		{
			Input.SetKey(KEY_A)
		}
		else if (window.isKeyPress(GLFW_KEY_S))
		{
			Input.SetKey(KEY_S)
		}
		else if (window.isKeyPress(GLFW_KEY_D))
		{
			Input.SetKey(KEY_D)
		}
	
		if (window.isMouseButtonPress(GLFW_MOUSE_BUTTON_LEFT))
		{
			std::cout << "mouse press!";
		}
		//glBegin(GL_TRIANGLES);
		//glVertex2f(-0.5, -0.5);
		//glVertex2f(0 , 1);
		//glVertex2f(0.5, -0.5);
		//glEnd();
	
		engine.Loop();

		window.update();
	}

	system("PAUSE");
	return 0;

}
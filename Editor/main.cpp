
#include <iostream>


#include "application.h"
using namespace sparky;
int main()
{
	
	//Window window("Sparky!", 1920, 1080);

	//float2 vector(1.0, 2.0);
	Application* app = Application::Get();



	app->Initialize();
	app->Run();
 

	system("PAUSE");
	return 0;

}
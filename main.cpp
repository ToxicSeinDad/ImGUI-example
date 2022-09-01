#include "gui.h"
#include <thread>
int __stdcall wWinMain(
	HINSTANCE instance,
	HINSTANCE previosInstance,
	PWSTR arguments,
	int commandShow)
{
	gui::CreateHWindow("Schummeltexteins", "Schummeltextzwei");
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::exit)
	{
		gui::BeginRender();
		gui::Render();
		gui::EndRender();

		std::this_thread::sleep_for(std::chrono::microseconds(10));
	}

	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();


	return EXIT_SUCCESS;
}
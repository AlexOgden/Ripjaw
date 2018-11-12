#pragma once

#ifdef RJ_PLATFORM_WINDOWS

extern Ripjaw::Application* Ripjaw::CreateApplication();

int main(int arc, char** argv)
{
	Ripjaw::Log::Init();
	RJ_CORE_INFO("Initialized Log!");

	auto app = Ripjaw::CreateApplication();
	app->Run();
	delete app;
}

#endif
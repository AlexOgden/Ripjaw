#pragma once

#ifdef RJ_PLATFORM_WINDOWS

extern Ripjaw::Application* Ripjaw::CreateApplication();

int main(int arc, char** argv)
{
	auto app = Ripjaw::CreateApplication();
	app->Run();
}
#endif
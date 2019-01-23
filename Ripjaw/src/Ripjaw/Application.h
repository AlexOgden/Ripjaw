#pragma once

#include "Core.h"
#include "Window.h"

namespace Ripjaw
{
	class RIPJAW_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};



	//Define in client
	Application* CreateApplication();
}

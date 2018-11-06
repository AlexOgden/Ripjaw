#pragma once

#include "Core.h"

namespace Ripjaw
{
	class RIPJAW_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//Define in client
	Application* CreateApplication();
}

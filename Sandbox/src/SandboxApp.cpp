#include <Ripjaw.h>

class Sandbox : public Ripjaw::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Ripjaw::Application* Ripjaw::CreateApplication()
{
	return new Sandbox();
}
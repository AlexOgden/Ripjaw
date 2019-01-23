#pragma once

#include "rjpch.h"

#include "Ripjaw/Core.h"
#include "Ripjaw/Events/Event.h"

namespace Ripjaw
{
	struct WindowProps
	{
		std::string m_title;
		uint32_t m_width;
		uint32_t m_height;

		WindowProps(const std::string& title = "Ripjaw Engine",
			uint32_t width = 1200,
			uint32_t height = 720)
			: m_title(title), m_width(width), m_height(height)
		{

		}
	};

	class RIPJAW_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
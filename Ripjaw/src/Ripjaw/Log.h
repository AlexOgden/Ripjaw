#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Ripjaw {
	class RIPJAW_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define RJ_CORE_ERROR(...)  ::Ripjaw::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RJ_CORE_WARN(...)   ::Ripjaw::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RJ_CORE_INFO(...)   ::Ripjaw::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RJ_CORE_TRACE(...)  ::Ripjaw::Log::GetCoreLogger()->trace(__VA_ARGS__)


#define RJ_ERROR(...)       ::Ripjaw::Log::GetClientLogger()->error(__VA_ARGS__)
#define RJ_WARN(...)        ::Ripjaw::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RJ_INFO(...)        ::Ripjaw::Log::GetClientLogger()->info(__VA_ARGS__)
#define RJ_TRACE(...)       ::Ripjaw::Log::GetClientLogger()->trace(__VA_ARGS__)
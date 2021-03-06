workspace "Ripjaw"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Ripjaw/GLFW/include"

include "Ripjaw/GLFW"

project "Ripjaw"
	location "Ripjaw"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "rjpch.h"
	pchsource "Ripjaw/src/rjpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/spdlog/include;",
		"%{IncludeDir.GLFW}"
	}
	
	links 
	{ 
		"GLFW"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"RJ_PLATFORM_WINDOWS",
		"RJ_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}


	filter "configurations:Debug"
		defines "RJ_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "RJ_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "RJ_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Ripjaw/spdlog/include;",
		"Ripjaw/src"
	}

	links
	{
		"Ripjaw"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"RJ_PLATFORM_WINDOWS"
	}


	filter "configurations:Debug"
		defines "RJ_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "RJ_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "RJ_DIST"
		optimize "On"

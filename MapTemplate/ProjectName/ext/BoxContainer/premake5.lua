project "BoxContainer"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	location ("%{wks.location}/%{prj.name}")
	targetdir ("%{LibraryTgtDir.BoxContainer}")
	objdir ("%{LibraryObjDir.BoxContainer}")

	files
	{
		"BoxContainer.hpp"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
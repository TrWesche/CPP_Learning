project "Adder"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	location ("%{wks.location}/%{prj.name}")
	targetdir ("%{LibraryTgtDir.Adder}")
	objdir ("%{LibraryObjDir.Adder}")

	files
	{
		"*.hpp"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
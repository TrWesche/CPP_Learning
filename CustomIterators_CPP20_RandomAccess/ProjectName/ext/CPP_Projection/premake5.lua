project "CPP_Projection"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	location ("%{wks.location}/%{prj.name}")
	targetdir ("%{LibraryTgtDir.CPP_Projection}")
	objdir ("%{LibraryObjDir.CPP_Projection}")

	files
	{
		"*.hpp",
		"*.cpp"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
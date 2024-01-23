project "STD_Vector"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	location ("%{wks.location}/%{prj.name}")
	targetdir ("%{LibraryTgtDir.STD_Vector}")
	objdir ("%{LibraryObjDir.STD_Vector}")

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
project "EntityContainer"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	location ("%{wks.location}/%{prj.name}")
	targetdir ("%{LibraryTgtDir.EntityContainer}")
	objdir ("%{LibraryObjDir.EntityContainer}")

	files
	{
		"*.hpp",
		"*.cpp"
	}

	includedirs
	{
	}

	libdirs
	{
	}

	links
	{
	}



	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
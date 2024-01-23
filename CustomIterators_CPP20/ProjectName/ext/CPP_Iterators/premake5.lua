project "CPP_Iterators"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	location ("%{wks.location}/%{prj.name}")
	targetdir ("%{LibraryTgtDir.CPP_Iterators}")
	objdir ("%{LibraryObjDir.CPP_Iterators}")

	files
	{
		"*.hpp",
		"*.cpp"
	}

	includedirs
	{
		"%{IncludeDir.HelperFunctions}",
	}

	libdirs
	{
		"%{LibraryTgtDir.HelperFunctions}",
	}

	links
	{
		"HelperFunctions",
	}



	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
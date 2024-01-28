project "ProjectMathModule"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
  	compileas "Module"

	location ("%{wks.location}/%{prj.name}")
	targetdir ("%{LibraryTgtDir.ProjectMathModule}")
	objdir ("%{LibraryObjDir.ProjectMathModule}")

	files
	{
		"*.ixx",
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

	filter "options:cc=gcc"
		defines "-fmodules-ts"
	filter "options:cc=clang"
		defines "-clang_something"


	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
project "ClassWithNestedLambda"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	location ("%{wks.location}/%{prj.name}")
	targetdir ("%{LibraryTgtDir.ClassWithNestedLambda}")
	objdir ("%{LibraryObjDir.ClassWithNestedLambda}")

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
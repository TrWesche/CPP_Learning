project "BoxContainer"
  kind "ConsoleApp"
  language "C++"
  cppdialect "C++20"

  location ("%{wks.location}/%{prj.name}")
  targetdir ("%{wks.location}/bin/" .. outputdir)
  objdir ("%{wks.location}/bin-int/" .. outputdir)

  includedirs
  {
    "src",
    "include"
  }

  links
  {
  }

  files {
    "src/**.hpp", 
    "src/**.cpp",
    "include/**.hpp",
    "include/**.cpp"
  }

  filter { "configurations:Debug" }
    defines { "DEBUG" }
    symbols "On"

  filter { "configurations:Release" }
    defines { "NDEBUG" }
    optimize "On"
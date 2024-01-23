project "ProjectName"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    -- staticruntime "on"

    location ("%{wks.location}/%{prj.name}")
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
      "src/**.hpp", 
      "src/**.cpp"
    }


    includedirs
    {
      "src",
      "ext/BoxContainer"
    }
    
    libdirs
    {
      "%{LibraryTgtDir.BoxContainer}"
    }

    links
    {
      "BoxContainer"
    }



    filter { "configurations:Debug" }
      defines { "DEBUG" }
      -- buildoptions "/MTd"
      -- runtime "Debug"
      symbols "On"

    filter { "configurations:Release" }
      defines { "NDEBUG" }
      -- buildoptions "/MT"
      -- runtime "Release"
      optimize "On"
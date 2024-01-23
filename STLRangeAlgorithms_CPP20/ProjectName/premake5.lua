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
      "ext/STD_ContainerChecks",
      "ext/STD_ForEach",
      "ext/STD_MaxMin",
      "ext/STD_Find",
      "ext/STD_Copy",
      "ext/STD_Sort",
      "ext/STD_Transform",
      "ext/Point",
      "ext/CPP_Projection",
      "ext/CPP_View",
    }
    
    libdirs
    {
      "%{LibraryTgtDir.STD_ContainerChecks}",
      "%{LibraryTgtDir.STD_ForEach}",
      "%{LibraryTgtDir.STD_MaxMin}",
      "%{LibraryTgtDir.STD_Find}",
      "%{LibraryTgtDir.STD_Copy}",
      "%{LibraryTgtDir.STD_Sort}",
      "%{LibraryTgtDir.STD_Transform}",
      "%{LibraryTgtDir.Point}",
      "%{LibraryTgtDir.CPP_Projection}",
      "%{LibraryTgtDir.CPP_View}",
    }

    links
    {
      "STD_ContainerChecks",
      "STD_ForEach",
      "STD_MaxMin",
      "STD_Find",
      "STD_Copy",
      "STD_Sort",
      "STD_Transform",
      "Point",
      "CPP_Projection",
      "CPP_View",
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
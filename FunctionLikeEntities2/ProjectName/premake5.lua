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
      "ext/BoxContainer",
      "ext/DecryptFunctor",
      "ext/EncryptFunctor",
      "ext/IsInRangeFunctor",
      "ext/ClassWithNestedLambda"
    }
    
    libdirs
    {
      "%{LibraryTgtDir.BoxContainer}",
      "%{LibraryTgtDir.DecryptFunctor}",
      "%{LibraryTgtDir.EncryptFunctor}",
      "%{LibraryTgtDir.IsInRangeFunctor}",
      "%{LibraryTgtDir.ClassWithNestedLambda}",
    }

    links
    {
      "BoxContainer",
      "DecryptFunctor",
      "EncryptFunctor",
      "IsInRangeFunctor",
      "ClassWithNestedLambda"
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
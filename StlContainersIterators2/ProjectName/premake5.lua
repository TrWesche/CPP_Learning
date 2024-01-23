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
      "ext/STD_Vector",
      "ext/STD_Array",
      "ext/STD_Deque",
      "ext/STD_FWDList",
      "ext/STD_List",
      "ext/STD_Pair",
      "ext/STD_Set",
      "ext/STD_Map",
      "ext/STD_Stack",
      "ext/STD_Queue",
      "ext/STD_PriorityQueue",

      "ext/Book",
    }
    
    libdirs
    {
      "%{LibraryTgtDir.STD_Vector}",
      "%{LibraryTgtDir.STD_Array}",
      "%{LibraryTgtDir.STD_Deque}",
      "%{LibraryTgtDir.STD_FWDList}",
      "%{LibraryTgtDir.STD_List}",
      "%{LibraryTgtDir.STD_Pair}",
      "%{LibraryTgtDir.STD_Set}",
      "%{LibraryTgtDir.STD_Map}",
      "%{LibraryTgtDir.STD_Stack}",
      "%{LibraryTgtDir.STD_Queue}",
      "%{LibraryTgtDir.STD_PriorityQueue}",

      "%{LibraryTgtDir.Book}",
    }

    links
    {
      "STD_Vector",
      "STD_Array",
      "STD_Deque",
      "STD_FWDList",
      "STD_List",
      "STD_Pair",
      "STD_Set",
      "STD_Map",
      "STD_Stack",
      "STD_Queue",
      "STD_PriorityQueue",

      "Book",
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
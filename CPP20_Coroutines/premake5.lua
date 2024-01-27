include "CustomActions.lua"

workspace "WorkspaceName"
    configurations {"Debug", "Release"}
    -- platforms {"x64", "x32"}
    architecture ("x64")
    location ("build")

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include the Relative Paths to the external libraries you are trying to use
group "Dependencies"
    -- include "ProjectName/ext/CPP_Iterators"
group ""

group "Core"
    include "ProjectName"
group ""


IncludeDir = {}
-- IncludeDir["CPP_Iterators"] = "%{wks.location}/../ProjectName/ext/CPP_Iterators"

LibraryObjDir = {}
-- LibraryObjDir["CPP_Iterators"] = ("%{wks.location}/bin-int/" .. outputdir .. "/CPP_Iterators")

LibraryTgtDir = {}
-- LibraryTgtDir["CPP_Iterators"] = ("%{wks.location}/bin-int/" .. outputdir .. "/CPP_Iterators")

Library = {}
-- Library["CPP_Iterators"] = "%{LibraryTgtDir.CPP_Iterators}/CPP_Iterators.lib"



-- filter {"configurations:Debug"}
--     buildoptions "/MTd"
--     runtime "Debug"
--     symbols "on"

-- filter {"configurations:Release"}
--     buildoptions "/MT"
--     runtime "Release"
--     optimize "on"
    
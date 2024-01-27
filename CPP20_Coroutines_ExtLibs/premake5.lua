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
    include "ProjectName/ext/coro"
group ""

group "Core"
    include "ProjectName"
group ""


IncludeDir = {}
IncludeDir["coro"] = "%{wks.location}/../ProjectName/ext/coro/include/coro"

LibraryObjDir = {}
LibraryObjDir["coro"] = ("%{wks.location}/bin-int/" .. outputdir .. "/coro")

LibraryTgtDir = {}
LibraryTgtDir["coro"] = ("%{wks.location}/bin-int/" .. outputdir .. "/coro")

Library = {}
Library["coro"] = "%{LibraryTgtDir.coro}/coro.lib"



-- filter {"configurations:Debug"}
--     buildoptions "/MTd"
--     runtime "Debug"
--     symbols "on"

-- filter {"configurations:Release"}
--     buildoptions "/MT"
--     runtime "Release"
--     optimize "on"
    
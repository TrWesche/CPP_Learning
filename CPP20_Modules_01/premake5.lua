-- https://premake.github.io/docs/compileas/ To figure out how to get premake5 to work for modules

include "CustomActions.lua"
include "CustomOptions.lua"

workspace "WorkspaceName"
    configurations {"Debug", "Release"}
    -- platforms {"x64", "x32"}
    architecture ("x64")
    location ("build")

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include the Relative Paths to the external libraries you are trying to use
group "External"
    -- include "ProjectName/ext/CPP_Iterators"
group ""

group "Modules"
    include "ProjectName/modules/math"
group ""

group "Core"
    include "ProjectName"
group ""



IncludeDir = {}
IncludeDir["ProjectMathModule"] = "%{wks.location}/../ProjectName/modules/math"

LibraryObjDir = {}
LibraryObjDir["ProjectMathModule"] = ("%{wks.location}/bin-int/" .. outputdir .. "/o/ProjectMathModule")

LibraryTgtDir = {}
LibraryTgtDir["ProjectMathModule"] = ("%{wks.location}/bin-int/" .. outputdir .. "/ProjectMathModule")

Library = {}
Library["ProjectMathModule"] = "%{LibraryTgtDir.CPP_Iterators}/ProjectMathModule.lib"



-- filter {"configurations:Debug"}
--     buildoptions "/MTd"
--     runtime "Debug"
--     symbols "on"

-- filter {"configurations:Release"}
--     buildoptions "/MT"
--     runtime "Release"
--     optimize "on"
    
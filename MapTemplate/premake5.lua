include "CustomActions.lua"

workspace "WorkspaceName"
    configurations {"Debug", "Release"}
    -- platforms {"x64", "x32"}
    architecture ("x64")
    location ("build")

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include the Relative Paths to the external libraries you are trying to use
group "Dependencies"
    -- include "ProjectName/ext/BoxContainer"
group ""

group "Core"
    include "ProjectName"
group ""


IncludeDir = {}
-- IncludeDir["BoxContainer"] = "%{wks.location}/ProjectName/ext/BoxContainer"

LibraryObjDir = {}
-- LibraryObjDir["BoxContainer"] = ("%{wks.location}/bin-int/" .. outputdir .. "/BoxContainer")

LibraryTgtDir = {}
-- LibraryTgtDir["BoxContainer"] = ("%{wks.location}/bin/" .. outputdir .. "/BoxContainer")

Library = {}
-- Library["BoxContainer"] = "%{LibraryDir.BoxContainer}/BoxContainer.lib"


-- filter {"configurations:Debug"}
--     buildoptions "/MTd"
--     runtime "Debug"
--     symbols "on"

-- filter {"configurations:Release"}
--     buildoptions "/MT"
--     runtime "Release"
--     optimize "on"
    
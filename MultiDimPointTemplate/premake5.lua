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
LibraryObjDir["Point"] = ("%{wks.location}/bin-int/" .. outputdir .. "/Point")

LibraryTgtDir = {}
-- LibraryTgtDir["BoxContainer"] = ("%{wks.location}/bin/" .. outputdir .. "/BoxContainer")
LibraryTgtDir["Point"] = ("%{wks.location}/bin/" .. outputdir .. "/Point")

Library = {}
-- Library["BoxContainer"] = "%{LibraryDir.BoxContainer}/BoxContainer.lib"
Library["Point"] = "%{LibraryTgtDir.Point}/Point.lib"


-- filter {"configurations:Debug"}
--     buildoptions "/MTd"
--     runtime "Debug"
--     symbols "on"

-- filter {"configurations:Release"}
--     buildoptions "/MT"
--     runtime "Release"
--     optimize "on"
    
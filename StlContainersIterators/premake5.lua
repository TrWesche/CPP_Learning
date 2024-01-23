include "CustomActions.lua"

workspace "WorkspaceName"
    configurations {"Debug", "Release"}
    -- platforms {"x64", "x32"}
    architecture ("x64")
    location ("build")

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include the Relative Paths to the external libraries you are trying to use
group "Dependencies"
    include "ProjectName/ext/STD_Vector"
    include "ProjectName/ext/STD_Array"
group ""

group "Core"
    include "ProjectName"
group ""


IncludeDir = {}
-- IncludeDir["STD_Vector"] = "%{wks.location}/ProjectName/ext/STD_Vector"

LibraryObjDir = {}
LibraryObjDir["STD_Vector"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Vector")
LibraryObjDir["STD_Array"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Array")

LibraryTgtDir = {}
LibraryTgtDir["STD_Vector"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Vector")
LibraryTgtDir["STD_Array"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Array")

Library = {}
Library["STD_Vector"] = "%{LibraryTgtDir.STD_Vector}/STD_Vector.lib"
Library["STD_Array"] = "%{LibraryTgtDir.STD_Array}/STD_Array.lib"


-- filter {"configurations:Debug"}
--     buildoptions "/MTd"
--     runtime "Debug"
--     symbols "on"

-- filter {"configurations:Release"}
--     buildoptions "/MT"
--     runtime "Release"
--     optimize "on"
    
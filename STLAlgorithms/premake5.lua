include "CustomActions.lua"

workspace "WorkspaceName"
    configurations {"Debug", "Release"}
    -- platforms {"x64", "x32"}
    architecture ("x64")
    location ("build")

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include the Relative Paths to the external libraries you are trying to use
group "Dependencies"
    include "ProjectName/ext/STD_ContainerChecks"
    include "ProjectName/ext/STD_ForEach"
    include "ProjectName/ext/STD_MaxMin"
    include "ProjectName/ext/STD_Find"
    include "ProjectName/ext/STD_Copy"
    include "ProjectName/ext/STD_Sort"
    include "ProjectName/ext/STD_Transform"
group ""

group "Core"
    include "ProjectName"
group ""


IncludeDir = {}
-- IncludeDir["STD_Vector"] = "%{wks.location}/ProjectName/ext/STD_Vector"

LibraryObjDir = {}
LibraryObjDir["STD_ContainerChecks"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_ContainerChecks")
LibraryObjDir["STD_ForEach"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_ForEach")
LibraryObjDir["STD_MaxMin"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_MaxMin")
LibraryObjDir["STD_Find"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Find")
LibraryObjDir["STD_Copy"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Copy")
LibraryObjDir["STD_Sort"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Sort")
LibraryObjDir["STD_Transform"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Transform")


LibraryTgtDir = {}
LibraryTgtDir["STD_ContainerChecks"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_ContainerChecks")
LibraryTgtDir["STD_ForEach"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_ForEach")
LibraryTgtDir["STD_MaxMin"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_MaxMin")
LibraryTgtDir["STD_Find"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Find")
LibraryTgtDir["STD_Copy"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Copy")
LibraryTgtDir["STD_Sort"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Sort")
LibraryTgtDir["STD_Transform"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Transform")


Library = {}
Library["STD_ContainerChecks"] = "%{LibraryTgtDir.STD_ContainerChecks}/STD_ContainerChecks.lib"
Library["STD_ForEach"] = "%{LibraryTgtDir.STD_ForEach}/STD_ForEach.lib"
Library["STD_MaxMin"] = "%{LibraryTgtDir.STD_MaxMin}/STD_MaxMin.lib"
Library["STD_Find"] = "%{LibraryTgtDir.STD_Find}/STD_Find.lib"
Library["STD_Copy"] = "%{LibraryTgtDir.STD_Copy}/STD_Copy.lib"
Library["STD_Sort"] = "%{LibraryTgtDir.STD_Sort}/STD_Sort.lib"
Library["STD_Transform"] = "%{LibraryTgtDir.STD_Transform}/STD_Transform.lib"


-- filter {"configurations:Debug"}
--     buildoptions "/MTd"
--     runtime "Debug"
--     symbols "on"

-- filter {"configurations:Release"}
--     buildoptions "/MT"
--     runtime "Release"
--     optimize "on"
    
include "CustomActions.lua"

workspace "WorkspaceName"
    configurations {"Debug", "Release"}
    -- platforms {"x64", "x32"}
    architecture ("x64")
    location ("build")

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include the Relative Paths to the external libraries you are trying to use
group "Dependencies"
    include "ProjectName/ext/BoxContainer"
    include "ProjectName/ext/EncryptFunctor"
    include "ProjectName/ext/DecryptFunctor"
    include "ProjectName/ext/IsInRangeFunctor"
    include "ProjectName/ext/ClassWithNestedLambda"
group ""

group "Core"
    include "ProjectName"
group ""


IncludeDir = {}
-- IncludeDir["BoxContainer"] = "%{wks.location}/ProjectName/ext/BoxContainer"

LibraryObjDir = {}
LibraryObjDir["BoxContainer"] = ("%{wks.location}/bin-int/" .. outputdir .. "/BoxContainer")
LibraryObjDir["EncryptFunctor"] = ("%{wks.location}/bin-int/" .. outputdir .. "/EncryptFunctor")
LibraryObjDir["DecryptFunctor"] = ("%{wks.location}/bin-int/" .. outputdir .. "/DecryptFunctor")
LibraryObjDir["IsInRangeFunctor"] = ("%{wks.location}/bin-int/" .. outputdir .. "/IsInRangeFunctor")
LibraryObjDir["ClassWithNestedLambda"] = ("%{wks.location}/bin-int/" .. outputdir .. "/ClassWithNestedLambda")

LibraryTgtDir = {}
LibraryTgtDir["BoxContainer"] = ("%{wks.location}/bin/" .. outputdir .. "/BoxContainer")
LibraryTgtDir["EncryptFunctor"] = ("%{wks.location}/bin/" .. outputdir .. "/EncryptFunctor")
LibraryTgtDir["DecryptFunctor"] = ("%{wks.location}/bin/" .. outputdir .. "/DecryptFunctor")
LibraryTgtDir["IsInRangeFunctor"] = ("%{wks.location}/bin/" .. outputdir .. "/IsInRangeFunctor")
LibraryTgtDir["ClassWithNestedLambda"] = ("%{wks.location}/bin/" .. outputdir .. "/ClassWithNestedLambda")

Library = {}
Library["BoxContainer"] = "%{LibraryDir.BoxContainer}/BoxContainer.lib"
Library["EncryptFunctor"] = "%{LibraryDir.EncryptFunctor}/EncryptFunctor.lib"
Library["DecryptFunctor"] = "%{LibraryDir.DecryptFunctor}/DecryptFunctor.lib"
Library["IsInRangeFunctor"] = "%{LibraryDir.IsInRangeFunctor}/IsInRangeFunctor.lib"
Library["ClassWithNestedLambda"] = "%{LibraryDir.ClassWithNestedLambda}/ClassWithNestedLambda.lib"


-- filter {"configurations:Debug"}
--     buildoptions "/MTd"
--     runtime "Debug"
--     symbols "on"

-- filter {"configurations:Release"}
--     buildoptions "/MT"
--     runtime "Release"
--     optimize "on"
    
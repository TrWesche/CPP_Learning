include "CustomActions.lua"

workspace "WorkspaceName"
    configurations {"Debug", "Release"}
    -- platforms {"x64", "x32"}
    architecture ("x64")
    location ("build")

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include the Relative Paths to the external libraries you are trying to use
group "Dependencies"
    include "ProjectName/ext/CPP_Iterators"
    include "ProjectName/ext/HelperFunctions"
    include "ProjectName/ext/EntityContainer"
group ""

group "Core"
    include "ProjectName"
group ""


IncludeDir = {}
IncludeDir["CPP_Iterators"] = "%{wks.location}/../ProjectName/ext/CPP_Iterators"
IncludeDir["HelperFunctions"] = "%{wks.location}/../ProjectName/ext/HelperFunctions"
IncludeDir["EntityContainer"] = "%{wks.location}/../ProjectName/ext/EntityContainer"

LibraryObjDir = {}
LibraryObjDir["CPP_Iterators"] = ("%{wks.location}/bin-int/" .. outputdir .. "/CPP_Iterators")
LibraryObjDir["HelperFunctions"] = ("%{wks.location}/bin-int/" .. outputdir .. "/HelperFunctions")
LibraryObjDir["EntityContainer"] = ("%{wks.location}/bin-int/" .. outputdir .. "/EntityContainer")


LibraryTgtDir = {}
LibraryTgtDir["CPP_Iterators"] = ("%{wks.location}/bin-int/" .. outputdir .. "/CPP_Iterators")
LibraryTgtDir["HelperFunctions"] = ("%{wks.location}/bin-int/" .. outputdir .. "/HelperFunctions")
LibraryTgtDir["EntityContainer"] = ("%{wks.location}/bin-int/" .. outputdir .. "/EntityContainer")


Library = {}
Library["CPP_Iterators"] = "%{LibraryTgtDir.CPP_Iterators}/CPP_Iterators.lib"
Library["HelperFunctions"] = "%{LibraryTgtDir.HelperFunctions}/HelperFunctions.lib"
Library["EntityContainer"] = "%{LibraryTgtDir.EntityContainer}/EntityContainer.lib"



-- filter {"configurations:Debug"}
--     buildoptions "/MTd"
--     runtime "Debug"
--     symbols "on"

-- filter {"configurations:Release"}
--     buildoptions "/MT"
--     runtime "Release"
--     optimize "on"
    
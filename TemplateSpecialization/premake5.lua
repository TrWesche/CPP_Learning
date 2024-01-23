include "CustomActions.lua"

workspace "WorkspaceName"
    configurations {"Debug", "Release"}
    -- platforms {"x64", "x32"}
    architecture ("x64")
    location ("build")

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include the Relative Paths to the external libraries you are trying to use
group "Dependencies"
    -- include "ProjectName/ext/Adder"
    -- include "ProjectName/ext/BoxContainer"
    -- include "ProjectName/ext/FriendFunction"
    -- include "ProjectName/ext/MapTwo"
    -- include "ProjectName/ext/Point"
group ""

group "Core"
    include "ProjectName"
group ""


IncludeDir = {}
-- IncludeDir["BoxContainer"] = "%{wks.location}/ProjectName/ext/BoxContainer"

LibraryObjDir = {}
LibraryObjDir["BoxContainer"] = ("%{wks.location}/bin-int/" .. outputdir .. "/BoxContainer")
LibraryObjDir["Point"] = ("%{wks.location}/bin-int/" .. outputdir .. "/Point")
LibraryObjDir["Adder"] = ("%{wks.location}/bin-int/" .. outputdir .. "/Adder")
LibraryObjDir["FriendFunction"] = ("%{wks.location}/bin-int/" .. outputdir .. "/FriendFunction")
LibraryObjDir["MapTwo"] = ("%{wks.location}/bin-int/" .. outputdir .. "/MapTwo")

LibraryTgtDir = {}
LibraryTgtDir["BoxContainer"] = ("%{wks.location}/bin/" .. outputdir .. "/BoxContainer")
LibraryTgtDir["Point"] = ("%{wks.location}/bin/" .. outputdir .. "/Point")
LibraryTgtDir["Adder"] = ("%{wks.location}/bin/" .. outputdir .. "/Adder")
LibraryTgtDir["FriendFunction"] = ("%{wks.location}/bin/" .. outputdir .. "/FriendFunction")
LibraryTgtDir["MapTwo"] = ("%{wks.location}/bin/" .. outputdir .. "/MapTwo")

Library = {}
Library["BoxContainer"] = "%{LibraryDir.BoxContainer}/BoxContainer.lib"
Library["Point"] = "%{LibraryTgtDir.Point}/Point.lib"
Library["Adder"] = "%{LibraryTgtDir.Adder}/Adder.lib"
Library["FriendFunction"] = "%{LibraryTgtDir.FriendFunction}/FriendFunction.lib"
Library["MapTwo"] = "%{LibraryTgtDir.MapTwo}/MapTwo.lib"


-- filter {"configurations:Debug"}
--     buildoptions "/MTd"
--     runtime "Debug"
--     symbols "on"

-- filter {"configurations:Release"}
--     buildoptions "/MT"
--     runtime "Release"
--     optimize "on"
    
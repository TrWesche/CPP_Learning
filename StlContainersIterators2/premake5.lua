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
    include "ProjectName/ext/STD_Deque"
    include "ProjectName/ext/STD_FWDList"
    include "ProjectName/ext/STD_List"
    include "ProjectName/ext/STD_Pair"
    include "ProjectName/ext/STD_Set"
    include "ProjectName/ext/STD_Map"
    include "ProjectName/ext/STD_Stack"
    include "ProjectName/ext/STD_Queue"
    include "ProjectName/ext/STD_PriorityQueue"
    include "ProjectName/ext/Book"
group ""

group "Core"
    include "ProjectName"
group ""


IncludeDir = {}
-- IncludeDir["STD_Vector"] = "%{wks.location}/ProjectName/ext/STD_Vector"

LibraryObjDir = {}
LibraryObjDir["STD_Vector"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Vector")
LibraryObjDir["STD_Array"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Array")
LibraryObjDir["STD_Deque"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Deque")
LibraryObjDir["STD_FWDList"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_FWDList")
LibraryObjDir["STD_List"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_List")
LibraryObjDir["STD_Pair"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Pair")
LibraryObjDir["STD_Set"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Set")
LibraryObjDir["STD_Map"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Map")
LibraryObjDir["STD_Stack"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Stack")
LibraryObjDir["STD_Queue"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Queue")
LibraryObjDir["STD_PriorityQueue"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_PriorityQueue")
LibraryObjDir["Book"] = ("%{wks.location}/bin-int/" .. outputdir .. "/Book")

LibraryTgtDir = {}
LibraryTgtDir["STD_Vector"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Vector")
LibraryTgtDir["STD_Array"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Array")
LibraryTgtDir["STD_Deque"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Deque")
LibraryTgtDir["STD_FWDList"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_FWDList")
LibraryTgtDir["STD_List"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_List")
LibraryTgtDir["STD_Pair"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Pair")
LibraryTgtDir["STD_Set"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Set")
LibraryTgtDir["STD_Map"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Map")
LibraryTgtDir["STD_Stack"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Stack")
LibraryTgtDir["STD_Queue"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_Queue")
LibraryTgtDir["STD_PriorityQueue"] = ("%{wks.location}/bin-int/" .. outputdir .. "/STD_STD_PriorityQueueQueue")
LibraryTgtDir["Book"] = ("%{wks.location}/bin-int/" .. outputdir .. "/Book")

Library = {}
Library["STD_Vector"] = "%{LibraryTgtDir.STD_Vector}/STD_Vector.lib"
Library["STD_Array"] = "%{LibraryTgtDir.STD_Array}/STD_Array.lib"
Library["STD_Deque"] = "%{LibraryTgtDir.STD_Deque}/STD_Deque.lib"
Library["STD_FWDList"] = "%{LibraryTgtDir.STD_FWDList}/STD_FWDList.lib"
Library["STD_List"] = "%{LibraryTgtDir.STD_List}/STD_List.lib"
Library["STD_Pair"] = "%{LibraryTgtDir.STD_Pair}/STD_Pair.lib"
Library["STD_Set"] = "%{LibraryTgtDir.STD_Set}/STD_Set.lib"
Library["STD_Map"] = "%{LibraryTgtDir.STD_Map}/STD_Map.lib"
Library["STD_Stack"] = "%{LibraryTgtDir.STD_Stack}/STD_Stack.lib"
Library["STD_Queue"] = "%{LibraryTgtDir.STD_Queue}/STD_Queue.lib"
Library["STD_PriorityQueue"] = "%{LibraryTgtDir.STD_PriorityQueue}/STD_PriorityQueue.lib"
Library["Book"] = "%{LibraryTgtDir.Book}/Book.lib"


-- filter {"configurations:Debug"}
--     buildoptions "/MTd"
--     runtime "Debug"
--     symbols "on"

-- filter {"configurations:Release"}
--     buildoptions "/MT"
--     runtime "Release"
--     optimize "on"
    
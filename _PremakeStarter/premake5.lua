include "dependencies.lua"

workspace "WorkspaceName"
    configurations {"Debug", "Release"}
    location ("build")

outputdir = "%{cfg.buildcfg}/${cfg.system}"

group "Core"
    include "ProjectName"
group ""
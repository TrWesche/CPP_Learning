include "dependencies.lua"

workspace "WorkspaceBC"
    configurations {"Debug", "Release"}
    location ("build")

outputdir = "%{cfg.buildcfg}/${cfg.system}"

group "Core"
    include "BoxContainer"
group ""
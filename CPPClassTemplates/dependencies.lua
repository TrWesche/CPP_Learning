IncludeDir = {}
IncludeDir["BoxContainer"] = "%{wks.location}/ProjectName/include/BoxContainer"


LibraryDir = {}
LibraryDir["BoxContainer"] = ("%{wks.location}/build/bin/" .. outputdir .. "/%{prj.name}")


Library = {}
Library["BoxContainer"] = "%{LibraryDir.BoxContainer}/BoxContainer.lib"
-- Clean Function --
newaction {
    trigger     = "clean",
    description = "Cleanup Build",
    execute     = function ()
       print("Executing build cleanup...")
       os.rmdir("./build")
       print("Done")
    end
}
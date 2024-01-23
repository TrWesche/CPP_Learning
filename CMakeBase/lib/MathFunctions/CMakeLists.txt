add_library(MathFunctions MathFunctions.cxx)


# Create a variable USE_CUSTOMMATH using option and set default to ON - Can be overwritten in command line using -DUSE_CUSTOMMATH=OFF
option(USE_CUSTOMMATH "Enable Custom Math Library" OFF)
# USE_CUSTOMMATH as a precompiled definition to our source files
if (USE_CUSTOMMATH)
    target_compile_definitions(MathFunctions PRIVATE "USE_CUSTOMMATH")
    add_library(SqrtLibrary STATIC mysqrt.cxx)
    target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()
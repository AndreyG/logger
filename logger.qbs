import qbs.base 1.0

StaticLibrary {
    name: "logger"

    files: [ 
        "src/stdafx.h",
        "src/debug_stream.cpp",
        "src/stopwatch.cpp",
        "include/logger/debug_stream.h",
        "include/logger/stopwatch.h",
    ]

    Depends { name: "cpp" }

    cpp.cppFlags: "-std=c++0x"
    cpp.includePaths: "include" 
    cpp.staticLibraries: "boost_chrono"
    //cpp.precompiledHeader: "src/stdafx.h"
}

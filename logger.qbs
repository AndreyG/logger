import qbs.base 1.0

StaticLibrary {
    name: "logger"

    files: [ 
        "src/stdafx.h",
        "src/debug_stream.cpp",
        "src/block.cpp",
        "src/stopwatch.cpp",
        "include/logger/args_expansion.h",
        "include/logger/message_type.h",
        "include/logger/debug_stream.h",
        "include/logger/block.h",
        "include/logger/trace.h",
        "include/logger/stopwatch.h",
    ]

    Depends { name: "cpp" }
    cpp.cppFlags: "-std=c++11"
    cpp.includePaths: "include"

    Export {
        Depends { name: "cpp" }

        cpp.includePaths: "include" 
        cpp.staticLibraries: ["boost_chrono", "boost_system"]
    }
}

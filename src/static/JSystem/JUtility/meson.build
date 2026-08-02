JUtility_srcs = files(
    'JUTAssert.cpp',
    'JUTConsole.cpp',
    'JUTDbPrint.cpp',
    'JUTDirectFile.cpp',
    'JUTDirectPrint.cpp',
    'JUTException.cpp',
    'JUTFader.cpp',
    'JUTFont.cpp',
    'JUTGamePad.cpp',
    'JUTGraphFifo.cpp',
    'JUTProcBar.cpp',
    'JUTResFont.cpp',
    'JUTVideo.cpp',
    'JUTXfb.cpp'
)

JUtility_lib = static_library('JUtility',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: JUtility_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += JUtility_lib

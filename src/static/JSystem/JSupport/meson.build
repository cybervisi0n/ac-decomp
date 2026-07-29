JSupport_srcs = files(
    'JSUFileStream.cpp',
    'JSUInputStream.cpp',
    'JSUList.cpp'
)

JSupport_lib = static_library('JSupport',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: JSupport_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += JSupport_lib
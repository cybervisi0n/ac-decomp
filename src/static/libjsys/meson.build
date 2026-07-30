libjsys_srcs = files(
    'jsyswrapper.cpp'
)

libjsys_lib = static_library('jsys',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: libjsys_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += libjsys_lib
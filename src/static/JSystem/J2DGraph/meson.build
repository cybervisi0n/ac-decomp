J2DGraph_srcs = files(
    'J2DGrafContext.cpp',
    'J2DOrthoGraph.cpp'
)

J2DGraph_lib = static_library('J2DGraph',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: J2DGraph_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += J2DGraph_lib
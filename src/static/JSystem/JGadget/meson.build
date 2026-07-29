JGadget_srcs = files(
    'linklist.cpp'
)

JGadget_lib = static_library('JGadget',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: JGadget_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += JGadget_lib
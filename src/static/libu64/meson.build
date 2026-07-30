libu64_srcs = files(
    'debug.c',
    'gfxprint_data.c',
    'gfxprint.c',
    'pad.c'
)

libu64_lib = static_library('u64',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: libu64_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += libu64_lib
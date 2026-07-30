libc64_srcs = files(
    '__osMalloc.c',
    'aprintf.c',
    'malloc.c',
    'math64.c',
    'qrand.c',
    'sleep.c',
    'sprintf.c'
)

libx64_lib = static_library('c64',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: libc64_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += libx64_lib
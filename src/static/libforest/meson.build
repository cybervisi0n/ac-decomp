libforest_srcs = files(
    'fault.c',
    'osreport.c',
    'ReconfigBATs.c'
)

if(build_target == 'gc')
libforest_srcs += files(
    'emu64/emu64.c'
)
else
libforest_srcs += files(
    'emu64/emu64.cpp'
)
endif

libforest_lib = static_library('forest',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: libforest_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += libforest_lib
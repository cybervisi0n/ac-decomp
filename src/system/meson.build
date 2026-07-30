system_srcs = files(
    'sys_dynamic.c',
    'sys_math_atan.c',
    'sys_math.c',
    'sys_math3d.c',
    'sys_matrix.c',
    'sys_romcheck.c',
    'sys_stacks.c',
    'sys_ucode.c',
    'sys_vimgr.c'
)

system_lib = static_library('system',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: system_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += system_lib
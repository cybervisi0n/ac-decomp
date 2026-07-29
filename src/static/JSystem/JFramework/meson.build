JFramework_srcs = files(
    'JFWDisplay.cpp',
    'JFWSystem.cpp'
)

JFramework_lib = static_library('JFramework',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: JFramework_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += JFramework_lib
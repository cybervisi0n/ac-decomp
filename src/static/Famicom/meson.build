Famicom_srcs = files(
    'famicom_nesinfo.cpp',
    'famicom.cpp',
    'ks_nes_core.cpp',
    'ks_nes_draw.cpp'
)

Famicom_lib = static_library('Famicom',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: Famicom_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += Famicom_lib
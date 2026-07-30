jaudio_NES_game_srcs = files(
    'audioheaders.cpp',
    'dummyprobe.cpp',
    'emusound.cpp',
    'game64.cpp',
    'kappa.cpp',
    'melody.cpp',
    'radio.cpp',
    'rhythm.cpp',
    'staff.cpp',
    'verysimple.cpp',
)

jaudio_NES_game_lib = static_library('jaudio_NES_game',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: jaudio_NES_game_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += jaudio_NES_game_lib
JKernel_srcs = files(
    'JKRAram.cpp',
    'JKRAramArchive.cpp',
    'JKRAramBlock.cpp',
    'JKRAramHeap.cpp',
    'JKRAramPiece.cpp',
    'JKRAramStream.cpp',
    'JKRArchivePri.cpp',
    'JKRArchivePub.cpp',
)

JKernel_lib = static_library('JKernel',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: JKernel_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += JKernel_lib
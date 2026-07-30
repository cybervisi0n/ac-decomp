JKernel_srcs = files(
    'JKRAram.cpp',
    'JKRAramArchive.cpp',
    'JKRAramBlock.cpp',
    'JKRAramHeap.cpp',
    'JKRAramPiece.cpp',
    'JKRAramStream.cpp',
    'JKRArchivePri.cpp',
    'JKRArchivePub.cpp',
    'JKRCompArchive.cpp',
    'JKRDecomp.cpp',
    'JKRDisposer.cpp',
    'JKRDvdAramRipper.cpp',
    'JKRDvdArchive.cpp',
    'JKRDvdFile.cpp',
    'JKRDvdRipper.cpp',
    'JKRExpHeap.cpp',
    'JKRFile.cpp',
    'JKRFileFinder.cpp',
    'JKRFileLoader.cpp',
    'JKRHeap.cpp',
    'JKRMemArchive.cpp',
    'JKRThread.cpp'
)

JKernel_lib = static_library('JKernel',
    include_directories: project_includes,
    pic: false,
    dependencies: libporpoise_dep,
    sources: JKernel_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += JKernel_lib
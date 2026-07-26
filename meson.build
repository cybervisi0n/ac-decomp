project('animalcrossing', ['c', 'cpp'],
    version: '1.0',
    default_options : [
        'buildtype=plain',
        'warning_level=0'
    ]
)

build_target = get_option('build_target')
libPorpoise_prj = subproject('libPorpoise')


shared_args = []

if(build_target == 'gc') 
shared_args += ['-DGAMECUBE']
endif

project_c_args = shared_args + [
    '-D_LANGUAGE_C'
]
project_cpp_args = shared_args + [
    '-D_LANGUAGE_C_PLUS_PLUS'
]

add_project_arguments(project_c_args, language: 'c', native: build_target != 'gc')
add_project_arguments(project_cpp_args, language: 'cpp', native: build_target != 'gc')

animalcrossing_link_args = []

eppc_lcf = meson.project_source_root() / 'include' / 'eppc.lcf'

if(build_target == 'gc')
    animalcrossing_link_args += [
        '-lcf',
        eppc_lcf
    ]
endif

project_includes = include_directories('include')

libporpoise_dep = dependency('libPorpoise')

subdir('src')

animalcrossing_exe = executable(
    'animalcrossing',
    sources: animalcrossing_srcs,
    dependencies: [ libporpoise_dep ],
    link_args: [ animalcrossing_link_args ],
    include_directories: [ project_includes ],
    native: build_target != 'gc',
)

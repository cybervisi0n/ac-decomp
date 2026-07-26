project('animalcrossing', ['c', 'cpp'],
    version: '1.0',
    default_options : [
        'buildtype=plain',
        'warning_level=0'
    ]
)

build_target = get_option('build_target')

libPorpoise_prj = subproject('libPorpoise')
animalcrossing_link_args = []

eppc_lcf = meson.project_source_root() / 'include' / 'eppc.lcf'

if(build_target == 'gc')
    animalcrossing_link_args += [
        '-lcf',
        eppc_lcf
    ]
endif

libporpoise_dep = dependency('libPorpoise')

subdir('src')

animalcrossing_exe = executable(
    'animalcrossing',
    sources: animalcrossing_srcs,
    dependencies: [ libporpoise_dep ],
    link_args: [ animalcrossing_link_args ],
    native: build_target != 'gc',
)

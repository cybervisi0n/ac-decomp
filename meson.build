project('animalcrossing', ['c', 'cpp'],
    version: '1.0',
    default_options : [
        'buildtype=plain',
        'warning_level=0'
    ]
)

build_target = get_option('build_target')
libPorpoise_prj = subproject('libPorpoise',
    default_options: [
        'dvd_game_id=GAFE',
        'dvd_company=01'
    ])


shared_args = [
    '-DF3DEX_GBI_2',
    '-I' + meson.current_build_dir() / 'GAFE01_00' / 'include',
    '-I' + meson.global_source_root()
]

if(build_target == 'gc') 
shared_args += ['-DGAMECUBE']
else
shared_args += [
    '-DPCPORT'
    ]
endif

project_c_args = shared_args + [
    '-D_LANGUAGE_C'
]
project_cpp_args = shared_args + [
    '-D_LANGUAGE_C_PLUS_PLUS',
    '-fpermissive'
]

add_project_arguments(project_c_args, language: 'c', native: build_target != 'gc')
add_project_arguments(project_cpp_args, language: 'cpp', native: build_target != 'gc')

# Decomp Toolkit
dtk_exe = find_program('dtk-tools/dtk', native: true)
python_exe = import('python').find_installation()
run_in_dir = files('scripts/run_in_dir.py')

# Extract GAFE01 assets
gafe_config_yml = meson.project_source_root() + '/config/GAFE01_00/config.yml'
gafe_dir = custom_target(
    command: [python_exe, run_in_dir, meson.project_source_root(), dtk_exe, 'dol', 'split', gafe_config_yml, meson.current_build_dir() + '/@OUTPUT@' ] , output: 'GAFE01_00')

gafe_custom_assets = custom_target(
    input: gafe_dir,
    command: ['tools/process_custom_assets.py', '--source-root', meson.project_source_root()],
    output: 'custom_assets_done.txt',
    )

gafe_assets_dep = declare_dependency(
    sources: [gafe_dir, gafe_custom_assets]
)

animalcrossing_link_args = []

eppc_lcf = meson.project_source_root() / 'include' / 'eppc.lcf'

if(build_target == 'gc')
    animalcrossing_link_args += [
        '-lcf',
        eppc_lcf
    ]
endif

if(build_target == 'linux32')
    animalcrossing_link_args += [
        '-m32'
    ]
endif

if(build_target == 'win32')
    animalcrossing_link_args += [
        '-Wl,--image-base,0x10000000'
    ]
endif

if(get_option('address_sanitizer') == true)
    animalcrossing_link_args += [
        '-fsanitize=address'
    ]
endif

project_includes = include_directories('include')
animalcrossing_libs = []


libporpoise_dep = dependency('libPorpoise')

subdir('src')

foresta_rel_lib = static_library('foresta.rel',
    include_directories: project_includes,
    pic: false,
    dependencies: [libporpoise_dep, gafe_assets_dep], 
    sources: [foresta_srcs],
    native: build_target != 'gc'
)
animalcrossing_libs += foresta_rel_lib

animalcrossing_exe = executable(
    'main',
    dependencies: [ libporpoise_dep, gafe_assets_dep ],
    sources: [ boot_srcs ],
    link_args: [ animalcrossing_link_args ],
    link_with: [ animalcrossing_libs ],
    include_directories: [ project_includes ],
    native: build_target != 'gc',
)

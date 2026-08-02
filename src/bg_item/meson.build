bg_item_srcs = files(
    'bg_cherry_item.c',
    'bg_item.c',
    'bg_police_item.c',
    'bg_post_item.c',
    'bg_winter_item.c',
    'bg_xmas_item.c'
)

bg_item_lib = static_library('bg_item',
    include_directories: project_includes,
    pic: false,
    dependencies: [libporpoise_dep, gafe_assets_dep],
    sources: bg_item_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += bg_item_lib
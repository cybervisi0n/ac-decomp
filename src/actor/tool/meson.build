actor_tool_srcs = files(
    'ac_t_anrium1.c',
    'ac_t_bag1.c',
    'ac_t_bag2.c',
    'ac_t_biscus1.c',
    'ac_t_biscus2.c',
    'ac_t_biscus3.c',
    'ac_t_biscus4.c',
    'ac_t_cobra1.c',
    'ac_t_cracker.c',
    'ac_t_flag.c',
    'ac_t_hanabi.c',
    'ac_t_hasu1.c',
    'ac_t_hat1.c',
    'ac_t_hat2.c',
    'ac_t_hat3.c',
    'ac_t_keitai.c',
    'ac_t_npc_sao.c',
    'ac_t_pistol.c',
    'ac_t_rei1.c',
    'ac_t_rei2.c',
    'ac_t_tama.c',
    'ac_t_tumbler.c',
    'ac_t_umbrella.c',
    'ac_t_utiwa.c',
    'ac_t_zinnia1.c',
    'ac_t_zinnia2.c'
)

actor_tool_lib = static_library('actor_tool',
    include_directories: project_includes,
    pic: false,
    dependencies: [libporpoise_dep, gafe_assets_dep],
    sources: actor_tool_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += actor_tool_lib
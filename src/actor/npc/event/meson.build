actor_npc_event_srcs = files(
    'ac_ev_angler.c',
    'ac_ev_artist.c',
    'ac_ev_broker.c',
    'ac_ev_broker2.c',
    'ac_ev_carpetPeddler.c',
    'ac_ev_castaway.c',
    'ac_ev_designer.c',
    'ac_ev_dokutu.c',
    'ac_ev_dozaemon.c',
    'ac_ev_ghost.c',
    'ac_ev_gypsy.c',
    'ac_ev_kabuPeddler.c',
    'ac_ev_majin.c',
    'ac_ev_miko.c',
    'ac_ev_pumpkin.c',
    'ac_ev_santa.c',
    'ac_ev_soncho.c',
    'ac_ev_soncho2.c',
    'ac_ev_speech_soncho.c',
    'ac_ev_turkey.c',
    'ac_ev_yomise.c',
)

actor_npc_event_lib = static_library('actor_npc_event',
    include_directories: project_includes,
    pic: false,
    dependencies: [libporpoise_dep, gafe_assets_dep],
    sources: actor_npc_event_srcs,
    native: build_target != 'gc'
)
animalcrossing_libs += actor_npc_event_lib
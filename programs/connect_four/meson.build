project('connect_four', 'cpp')

incdir = include_directories('./Catch2/single_include/catch2')

subdir('connect_four_game')

files = files(
    'main.cpp',
    'connect_four_game/connect_four_game.cpp',
    'connect_four_main/connect_four_main.cpp',
    'connect_four_player/connect_four_player.cpp',
    'connect_four_player/connect_four_player_random.cpp',
    'connect_four_player/connect_four_player_stdin.cpp'
)

executable('connect_four', files, include_directories : incdir, dependencies : [] )
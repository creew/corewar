cmake_minimum_required(VERSION 3.14)
project(vm C)

set(CMAKE_C_STANDARD 11)


include_directories(.
        ./../common_resources
        ./../libft/includes
        ./visu/includes
        ./includes
        ~/.brew/include/SDL2
        )

add_executable(vm
        ./srcs/vm.c
        ./srcs/read_champ.c
        ./srcs/read_be.c
        ./srcs/read_options.c
        ./srcs/control.c
        ./srcs/game_field.c
        ./visu/srcs/init.c
        ./visu/srcs/deinit.c
        ./visu/srcs/print.c
        ./visu/srcs/reload_fonts.c
        ./visu/srcs/process.c
        visu/srcs/draw_all.c)

add_dependencies(vm libft_target)

find_library(SDL2s SDL2 ~/.brew/lib)
find_library(SDL2i SDL2_image ~/.brew/lib)
find_library(SDL2t SDL2_ttf ~/.brew/lib)
find_library(SDL2g SDL2_gfx ~/.brew/lib)
find_library(FT ft ${PROJECT_SOURCE_DIR}/../libft)

target_link_libraries(vm PUBLIC ${SDL2s} ${SDL2i} ${SDL2t} ${SDL2g})
target_link_libraries(vm PUBLIC ${FT})

add_custom_target(
        libft_target
        COMMAND make
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/../libft
)

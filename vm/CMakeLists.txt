cmake_minimum_required(VERSION 3.14)
project(vm C)

set(CMAKE_C_STANDARD 11)

include_directories(.
        ./../common_resources
        ./../libft/includes
        ./../ft_printf/includes
        ./visu/includes
        ./includes
        ~/.brew/include/SDL2
        /usr/include/SDL2
        )

add_executable(vm
        ./../common_resources/op.c
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
        ./visu/srcs/draw_all.c
        ./srcs/dl_list.c
        ./srcs/processes.c
        srcs/check_arguments.c srcs/read_values.c srcs/run_comands.c)

add_dependencies(vm libft_target)
add_dependencies(vm ft_printf_target)

find_library(SDL2s SDL2 ~/.brew/lib)
find_library(SDL2i SDL2_image ~/.brew/lib)
find_library(SDL2t SDL2_ttf ~/.brew/lib)
find_library(SDL2g SDL2_gfx ~/.brew/lib)

find_library(FT ft ${PROJECT_SOURCE_DIR}/../libft)
find_library(FT_PRINTF ftprintf ${PROJECT_SOURCE_DIR}/../ft_printf)

target_link_libraries(vm PUBLIC ${SDL2s} ${SDL2i} ${SDL2t} ${SDL2g})
target_link_libraries(vm PUBLIC ${FT})
target_link_libraries(vm PUBLIC ${FT_PRINTF})

add_custom_target(
        libft_target
        COMMAND make
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/../libft
)

add_custom_target(
        ft_printf_target
        COMMAND make
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/../ft_printf
)

cmake_minimum_required(VERSION 3.14)
project(vm C)

set(CMAKE_C_STANDARD 11)

include_directories(.
        ./../common_resources
        ./../libft/includes
        ./../ft_printf/includes
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
        ./srcs/dl_list.c
        ./srcs/processes.c
        ./srcs/check_arguments.c
        srcs/run_commands.c
        ./srcs/visu/init.c
        ./srcs/visu/deinit.c
        ./srcs/visu/print.c
        ./srcs/visu/reload_fonts.c
        ./srcs/visu/process.c
        ./srcs/visu/draw_all.c
        ./srcs/visu/draw_info.c
        ./srcs/create_dump.c)

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

cmake_minimum_required(VERSION 3.14)
project(vm C)

set(CMAKE_C_STANDARD 11)

include_directories(.
        ./../common_resources
        ./../libft/includes
        ./includes
        )

add_executable(vm
        ./srcs/vm.c
        ./srcs/read_champ.c
        ./srcs/read_be.c
        ./srcs/read_options.c
        ./srcs/control.c
        ./srcs/game_field.c
        )

add_dependencies(vm libft_target)

find_library(FT ft ${PROJECT_SOURCE_DIR}/../libft)
target_link_libraries(vm PUBLIC ${FT})

add_custom_target(
        libft_target
        COMMAND make
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/../libft
)

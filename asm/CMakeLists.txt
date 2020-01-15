cmake_minimum_required(VERSION 3.15)
project(asm C)

set(CMAKE_C_STANDARD 11)

include_directories(
        ./../common_resources
        ./../libft/includes
        ./../ft_printf/includes
        .)

add_executable(asm
        adding.c
        adding2.c
        assembler.c
        assembler.h
        awm.c
        awm.h
        clears.c
        convertation.c
        delete_comments.c
        exit2.c
        fill_instr.c
        ft_exit.c
        init_awm.c
        main.c
        my_librires_functions.c
        op.c
        op.h
        valid_args.c
        valid_args_commands.c
        valid_args_commands2.c
        valid_args_commands3.c
        valid_commands.c
        valid_commands2.c
        valid_commands3.c
        valid_names.c
        what_is_it.c
        what_is_it2.c)

add_dependencies(asm libft_target)
add_dependencies(asm ft_printf_target)

find_library(FT ft ${PROJECT_SOURCE_DIR}/../libft)
find_library(FT_PRINTF ftprintf ${PROJECT_SOURCE_DIR}/../ft_printf)

target_link_libraries(asm PUBLIC ${FT})
target_link_libraries(asm PUBLIC ${FT_PRINTF})

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

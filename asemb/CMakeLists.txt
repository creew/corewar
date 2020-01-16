cmake_minimum_required(VERSION 3.15)
project(asm C)

set(CMAKE_C_STANDARD 11)

include_directories(
        ./../common_resources
        ./../libft/includes
        ./../ft_printf/includes
        ./includes
        src)

add_executable(asm
        src/adding.c
        src/adding2.c
        src/assembler.c
        src/awm.c
        src/clears.c
        src/convertation.c
        src/delete_comments.c
        src/exit2.c
        src/fill_instr.c
        src/ft_exit.c
        src/init_awm.c
        src/main.c
        src/my_librires_functions.c
        ../common_resources/op.c
        src/valid_args.c
        src/valid_args_commands.c
        src/valid_args_commands2.c
        src/valid_args_commands3.c
        src/valid_commands.c
        src/valid_commands2.c
        src/valid_commands3.c
        src/valid_names.c
        src/what_is_it.c
        src/what_is_it2.c)

add_dependencies(asm libft_target)
add_dependencies(asm ft_printf_target)

find_library(FT ft ../libft)
find_library(FT_PRINTF ftprintf ../ft_printf)

target_link_libraries(asm PUBLIC ${FT})
target_link_libraries(asm PUBLIC ${FT_PRINTF})

add_custom_target(
        libft_target
        COMMAND make
        WORKING_DIRECTORY ../../libft
)

add_custom_target(
        ft_printf_target
        COMMAND make
        WORKING_DIRECTORY ../../ft_printf
)

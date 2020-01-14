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
        srcs/init_vm.c
        ./srcs/dl_list.c
        srcs/process_cycle.c
        ./srcs/check_arguments.c
        ./srcs/visu/init.c
        ./srcs/visu/deinit.c
        ./srcs/visu/print.c
        ./srcs/visu/reload_fonts.c
        ./srcs/visu/process.c
        ./srcs/visu/draw_all.c
        ./srcs/visu/draw_info.c
        ./srcs/create_dump.c srcs/parse_arg.c srcs/errors.c srcs/visu/get_color.c srcs/commands/process_live_run.c srcs/commands/process_ld_run.c srcs/commands/process_st_run.c srcs/commands/process_add_run.c srcs/commands/process_sub_run.c srcs/commands/process_and_run.c srcs/commands/process_or_run.c srcs/commands/process_xor_run.c srcs/commands/process_zjmp_run.c srcs/commands/process_ldi_run.c srcs/commands/process_sti_run.c srcs/commands/process_fork_run.c srcs/commands/process_lld_run.c srcs/commands/process_lldi_run.c srcs/commands/process_lfork_run.c srcs/commands/process_aff_run.c srcs/commands/get_command_arg.c srcs/visu/draw_carriages.c srcs/visu/reload_carriages.c srcs/exec_process.c srcs/check_op_types.c)

add_dependencies(vm libft_target)
add_dependencies(vm ft_printf_target)

find_library(SDL2s SDL2 ~/.brew/lib)
find_library(SDL2t SDL2_ttf ~/.brew/lib)
find_library(SDL2g SDL2_gfx ~/.brew/lib)

find_library(FT ft ${PROJECT_SOURCE_DIR}/../libft)
find_library(FT_PRINTF ftprintf ${PROJECT_SOURCE_DIR}/../ft_printf)

target_link_libraries(vm PUBLIC ${SDL2s} ${SDL2t} ${SDL2g})
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

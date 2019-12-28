cmake_minimum_required(VERSION 3.14)
project(ftprintf C)

set(CMAKE_C_STANDARD 11)

include_directories(.
        ./includes)

add_library(ftprintf
        srcs/add_double.c
        srcs/add_paddings.c
        srcs/add_prefix.c
        srcs/add_to_out.c
        srcs/add_unsigned.c
        srcs/calc_double.c
        srcs/ft_printf.c
        srcs/long_ariph.c
        srcs/parse_character.c
        srcs/parse_double.c
        srcs/parse_flags.c
        srcs/parse_format.c
        srcs/parse_lenmod.c
        srcs/parse_precision.c
        srcs/parse_signed.c
        srcs/parse_string.c
        srcs/parse_type.c
        srcs/parse_unsigned.c
        srcs/parse_width.c
        srcs/sub_functions.c
        srcs/callbacks.c
        srcs/parse_colors.c
        srcs/main_funcs.c)

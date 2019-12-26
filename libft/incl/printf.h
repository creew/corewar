/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:12:37 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINTF_H
# define _PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>

/*
** Bonus part ANSI COLORS for background & print outputs;
*/

# define BLACK(string)			"\x1b[30m" string "\x1b[0m"
# define RED(string)			"\x1b[31m" string "\x1b[0m"
# define GREEN(string)			"\x1b[32m" string "\x1b[0m"
# define YELLOW(string)			"\x1b[33m" string "\x1b[0m"
# define BLUE(string)			"\x1b[34m" string "\x1b[0m"
# define MAGENTA(string)		"\x1b[35m" string "\x1b[0m"
# define CYAN(string)			"\x1b[36m" string "\x1b[0m"
# define GREY(string)			"\x1b[37m" string "\x1b[0m"
# define BLACK_BACK(string)		"\x1b[40m" string "\x1b[0m"
# define RED_BACK(string)		"\x1b[41m" string "\x1b[0m"
# define GREEN_BACK(string)		"\x1b[42m" string "\x1b[0m"
# define YELLOW_BACK(string)	"\x1b[43m" string "\x1b[0m"
# define BLUE_BACK(string)		"\x1b[44m" string "\x1b[0m"
# define MAGENTA_BACK(string)	"\x1b[45m" string "\x1b[0m"
# define CYAN_BACK(string)		"\x1b[46m" string "\x1b[0m"
# define GREY_BACK(string)		"\x1b[47m" string "\x1b[0m"

/*
** Union to get sign of 0 at ft_print_float;
*/

typedef union
{
	float						pf_union;
	struct
	{
		unsigned int			mantisa : 23;
		unsigned int			exponent : 8;
		unsigned int			sign : 1;
	}							float_parts;
}								t_float_union;

/*
** The var has following using:
** 			type_conv: to get type of conversation as %d, %f, %p and ext;
** 			num_elem: quantity of elements on output;
** 			*_mask: different type of mask;
** 			spaces: int of spaces, depends on flag can be ' ' or '0';
** 			n_value: used in case of negative integers;
** 			sizeof_num: the value of quantity digits;
** 			arr_num: array of digits;
*/

typedef struct					s_struct
{
	char						*conv_mask;
	char						type_conv;
	char						*format;
	size_t						i;
	size_t						g;
	int							num_elen;
	char						*flag_mask;
	char						type_flag[5];
	int							spaces;
	int							precision;
	char						*mod_mask;
	char						type_mod[3];
	int							tmp_flag;
	int							n_value;
	int							sizeof_num;
	char						arr_num[27];
	int							prec_value;
	char						hesh[3];
}								t_struct;

t_struct						g_pfstr;

int								ft_printf(const char *format, ...);
void							ft_initial(const char *format);
void							ft_check_begin_flags(int x, int j);
int								ft_check_is_flag(char c);
int								ft_conv_mask(char s);
void							ft_parser(va_list args);
void							ft_switch_print(va_list args);
void							ft_print_s(char *s, int precision);
void							ft_print_d(long long int num);
void							ft_print_c(char s);
void							ft_print_spc(int num);
void							ft_print_str(char *str);
void							ft_restart_flags(void);
void							ft_print_ou(unsigned long num);
void							ft_print_xxp(unsigned long int num);
void							ft_print_float(long double num);
int								ft_atoi(const char *src);
int								ft_strlen(const char *str);
int								ft_isdigit(int c);
void							ft_print_prc(void);
int								ft_check_is_flag(char c);
void							ft_print_spc_str(void);
void							ft_print_spc_d(char c);
void							ft_display_string(char *str);
void							ft_itoa_base(unsigned long long n, int base);
void							ft_del_flag(char c);
char							*ft_strjoin(char const *s1, char const *s2);
void							ft_print_sign(char chr);
void							ft_simple_zero();
void							ft_prep_conv(void);
void							ft_print_char(int chr);
char							*ft_strcpy(char *dest, const char *src);
double							ft_prec_dbl_round(long double num,
								long double n);
void							ft_print_num_float(unsigned long long num);
void							ft_print_float_right(long
								double num);
void							ft_float_negat(long double *num,
								long double *tmp_num);
int								ft_check_inf(long double *num);
void							ft_exception_float(long double *num,
								long double *tmp_num);
void							ft_check_sign_float(long double *num);
void							ft_simple_zero_add(char *tmp);

#endif

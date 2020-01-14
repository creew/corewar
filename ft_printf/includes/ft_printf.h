/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:36:34 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <wchar.h>

# define ABS(a) ((a) < 0 ? -(a) : (a))
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX(a, b) ((a) > (b) ? (a) : (b))

# define BUF_SIZE	64

# define FLAGS_STR "+- #0"
# define FLAG_PLUS	1
# define FLAG_MINUS	2
# define FLAG_SPACE	4
# define FLAG_HASH	8
# define FLAG_NULL	16
# define FLAG_APOSTROFE 32

# define TYPES_STR "cCsSpdDiIoOuUxXfF"

# define DEPRECATED_STR "DOUSC"

# define LENMOD_STR "hljtzL"
# define LENMOD_HH	1
# define LENMOD_H	2
# define LENMOD_L	3
# define LENMOD_LL	4
# define LENMOD_J	5
# define LENMOD_T	6
# define LENMOD_Z	7
# define LENMOD_BL	8

# define MANT_NAN	(3ull << 62)
# define MANT_INF	(1ull << 63)

# define ANSI_RESET			"\e[0m"
# define ANSI_BLACK			"\e[30m"
# define ANSI_RED			"\e[31m"
# define ANSI_GREEN			"\e[32m"
# define ANSI_YELLOW		"\e[33m"
# define ANSI_BLUE			"\e[34m"
# define ANSI_PURPLE		"\e[35m"
# define ANSI_CYAN			"\e[36m"
# define ANSI_WHITE			"\e[37m"

# define ANSI_BG_GREEN		"\e[42m"
# define ANSI_BG_YELLOW		"\e[43m"
# define ANSI_BG_CYAN		"\e[46m"

typedef unsigned long long	t_ullong;

typedef unsigned long		t_ulong;

typedef long long			t_llong;

typedef long double			t_ldouble;

typedef unsigned int		t_uint;

typedef struct	s_snparam
{
	char		*s;
	size_t		size;
}				t_snparam;

typedef union	u_bldouble
{
	t_ldouble	val;
	struct		s_double
	{
		t_ulong	man:64;
		t_ulong	exp:15;
		t_ulong	sign:1;
	}			bldbl;
}				t_bldouble;

typedef struct	s_print
{
	char		buf[BUF_SIZE];
	size_t		buf_len;

	void		(*write_func)(void **, char *, size_t);
	void		*write_param;

	int			type;
	int			is_precision;
	int			flags;
	int			width;
	int			precision;
	int			lenmod;
	int			pre_len;
	int			pad_len;
	int			str_len;
	int			point_len;
	int			is_val;
	int			is_neg;
	int			max_rlen;
}				t_print;

typedef struct	s_fpoint
{
	t_ulong		is_neg;
	long		shift;
	long		exp;
	t_ulong		mant;
	t_llong		lval;
	t_llong		rval;
}				t_fpoint;

typedef struct	s_longb
{
	t_uint		val[100];
	int			max_size;
	int			size;
	size_t		base;
}				t_longb;

int				ft_printf(const char *format, ...);
int				ft_sprintf(char *s, const char *format, ...);
int				ft_snprintf(char *s, size_t size, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

int				ft_allprintf(const char *format, va_list *ptr,
								void (f)(void **, char *, size_t), void *param);

int				add_to_out(t_print *print, char c);
int				addw_to_out(t_print *print, wint_t wc);
void			flush_buf(t_print *print);

int				parse_flags(t_print *print, const char *format);
int				parse_width(t_print *print, const char *format, va_list *ptr);
int				parse_precision(t_print *print, const char *format,
								va_list *ptr);
int				parse_type(t_print *print, const char *format);
int				parse_lenmod(t_print *print, const char *format);

int				parse_format(t_print *print, va_list *ptr);
int				parse_character(char type, t_print *print, va_list *ptr);
int				parse_string(char type, t_print *print, va_list *ptr);

int				add_c_with_flag(t_print *print, char *c, int len);
int				add_wc_with_flag(t_print *print, wchar_t *wc, int len);
int				add_pre_paddings(t_print *print);
int				add_post_paddings(t_print *print);
int				add_prefix(t_print *print);

int				get_unsigned_length(unsigned long long val, size_t base,
						unsigned long long *powout);
int				add_unsigned_base(t_print *print, unsigned long long val,
						size_t base);
int				parse_unsigned_base(t_print *print, va_list *ptr, int base);
int				parse_signed_base(t_print *print, va_list *ptr, int base);
int				parse_double(t_print *print, va_list *ptr);

int				calc_lval(t_fpoint *fdata, t_longb *lval);
int				calc_rval(t_fpoint *fdata, t_longb *rval);
int				add_double(t_print *print, t_longb *lval, t_longb *rval);
int				round_double(t_print *print, t_fpoint *fdata,
						t_longb *lval, t_longb *rval);

int				init_longb(t_longb *longb, t_ulong val);
int				add_longb(t_longb *a, t_longb *b);
int				div2_longb_uint(t_longb *longb);
int				div_longb_uint(t_longb *longb, t_uint a);
int				add_longb_uint(t_longb *a, t_uint b);

int				init_max_val(t_longb *val);
int				init_half_val(t_longb *val);
int				get_longb_len(t_longb *longb);
void			add_precision(t_print *print);

void			pf_bzero(void *s, size_t n);
int				pf_isdigit(int c);
char			*pf_strchr(const char *s, int c);
size_t			pf_strlen(const char *s);
int				pf_tolower(int c);

int				add_pad_and_uval(t_print *print, t_ullong val, int base);
int				calc_digit_pre_len(t_print *print);
int				parse_cstr(t_print *print, char *str);
int				get_val_by_pos(t_longb *longb, int pos);
int				longb_cmpn(t_longb *a, t_longb *b, int n);

void			fp_write_c(void **param, char *data, size_t len);
void			s_write_c(void **param, char *data, size_t len);
void			sn_write_c(void **param, char *data, size_t len);
void			fp_write_fd(void **param, char *data, size_t len);

int				parse_colors(t_print *print, const char **format);
#endif

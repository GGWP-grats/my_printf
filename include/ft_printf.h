/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:57:45 by wquenten          #+#    #+#             */
/*   Updated: 2021/01/24 10:58:30 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# ifndef TRUE
#  define TRUE 1
#  define FALSE 0
# endif
# define ARR_BASE "0123456789abcdef0123456789ABCDEF"

typedef struct	s_pft
{
	int			ladjust;
	int			f_prec;
	int			capital;
	int			zero;
	int			space;
	int			plus;
	int			sharp;
	int			prec;
	int			width;
	char		prefix[2];
	int			base;
}				t_pft;

int				ft_printf(const char *format, ...);
int				start_pf(const char *format, va_list *argp);
void			putchar_c(char c, int *ret);
void			putnum_base(long i, t_pft *set, int *ret);
void			u_putnum_base(unsigned long i, t_pft *set, int *ret);
void			ll_putnum_base(long long i, t_pft *set, int *ret);
void			ull_putnum_base(unsigned long long i, t_pft *set, int *ret);
int				print_width(t_pft *set, int *ret);
void			do_print(const char **format, va_list *argp, t_pft *set, \
																int *ret);
void			putf_i(int i, t_pft *set, int *ret);
void			putf_u(unsigned int i, t_pft *set, int *ret);
void			putf_s(char *s, t_pft *set, int *ret);
void			putf_c(char c, t_pft *set, int *ret);
void			putf_p(void *p, t_pft *set, int *ret);
void			putf_x(t_pft *set, int *ret);
void			putf_ll(long long i, t_pft *set, int *ret);
void			putf_llu(unsigned long long i, t_pft *set, int *ret);
void			get_flags(const char **format, va_list *argp, t_pft *set);
void			get_set(const char **format, va_list *argp, t_pft *set);
void			bonus(const char **format, va_list *argp, t_pft *set, int *ret);

#endif

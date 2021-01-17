#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdio.h>
#include <unistd.h> 
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
# ifndef TRUE
#  define TRUE 1
#  define FALSE 0
# endif
typedef struct	s_pft
{
	int			f_ladjust;
	int			f_prec;
	int			f_capitals;
	int			zero;
	int			prec_width;
	int			width;
	int			base;
}				t_pft;

int				pft_atoi(const char **format);
int				ft_printf(const char *format, ...);
int				print(const char *format, va_list *argp);
void			putchar_c(char c, int *ret);
void			putf_i(int i, t_pft *set, int *ret);
void			putf_ui(unsigned int i, t_pft *set, int *ret);
void			putf_s(char *s, t_pft *set, int *ret);
void			putf_c(char c, t_pft *set, int *ret);
void			get_set(const char **format, va_list *argp, t_pft *set);
void			do_print(const char **format, va_list *argp, t_pft *set, int *ret);
void			print_width(t_pft *set, int *ret);

void			print_flags(t_pft *set);
#endif

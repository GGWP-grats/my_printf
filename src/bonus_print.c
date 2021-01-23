#include "ft_printf.h"

void		bonus(const char **format, va_list *argp, t_pft *set, int *ret)
{
	int *n;

	if (**format == 'n' && (n = va_arg(*argp, int *)))
		*n = *ret;
	else 
		(*format)--;
	(void)*set;
}

void		putf_x(t_pft *set, int *ret)
{
	if (set->sharp && (set->prec || !set->f_prec))
	{
		putchar_c('0', ret);
		set->capital == 16 ? putchar_c('X', ret) : putchar_c('x', ret);
	}
	set->sharp = 0;
}

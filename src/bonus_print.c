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

#include "ft_printf.h"
int			check_null_str(char *s, t_pft *set, int *ret)
{
	if (s)
		return (0);
	if (set->f_prec == FALSE || 
			(set->f_prec && set->prec > 5))
		return (-1);
	if (set->f_prec)
		print_width(set, ret);
	return (1);
}

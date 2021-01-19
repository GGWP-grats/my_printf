#include "ft_printf.h"
int			check_null_str(char *s, t_pft *set, int *ret)
{
	if (s)
		return (0);
	if (set->f_prec == FALSE || 
			(set->f_prec && set->prec_width > 5))
		return (-1);
	if (set->f_prec)
		print_width(set, ret);
	return (1);
}

int			pft_atoi(const char **format)
{
	int i;
	int sign;

	sign = 1;
	i = 0;
	if (**format == '+' || **format == '-')
	{
		if (**format == '-')
			sign = -1;
		(*format)++;
	}
	while (ft_isdigit(**format))
	{
		i = i * 10 + ft_ctod(**format);
		(*format)++;
	}
	return (i * sign);
}

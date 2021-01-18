#include "ft_printf.h"

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

#include "ft_printf.h"

/*
** main goal is to write printf
** Mandatory part
** with following conversions:
**
**		 c s p d i u x X %
**
** and manage flags:
**
**			- 0 . * 
**
*/

void		putchar_c(char c, int *ret)
{
	*ret += 1;
	write(1, &c, 1);
}

void		putnum_base(long int i, t_pft *set, int *ret)
{		
	int len;
	
	len = set->base;
	if (i < 0 && (i = -i))
		putchar_c('-', ret);
	if (i >= len)
	{
		putnum_base(i / len, set, ret);
		putnum_base(i % len, set, ret);
	}
	else if (i < len)
		putchar_c(ARR_BASE[i + set->capital], ret);
}

void		u_putnum_base(unsigned long int i, t_pft *set, int *ret)
{		
	unsigned int len;
	
	len = set->base;
	if (i >= len)
	{
		u_putnum_base(i / len, set, ret);
		u_putnum_base(i % len, set, ret);
	}
	else if (i < len)
		putchar_c(ARR_BASE[i + set->capital], ret);
}

void		print_width(t_pft *set, int *ret)
{
	char c;
	int i;
	
	i = 0;
	c = ' ';
	if (set->zero)
		c = '0';
	while (i++ < set->width)
		putchar_c(c, ret);
}

void		do_print(const char **format, va_list *argp, t_pft *set, int *ret)
{
	char 	*s;
	char 	c;
	int		i;

	if (**format == 'c' && (c = va_arg(*argp, int)))
		putf_c(c, set, ret);
	else if (**format == 's' && (s = va_arg(*argp, char *)))
		putf_s(s, set, ret);
	else if ((**format == 'd' || **format == 'i') && (i = va_arg(*argp, int)))
		putf_i(i, set, ret);
	else if (**format == 'u' && (i = va_arg(*argp, int)))
		putf_u(i, set, ret);
	else if (**format == 'x' && (i = va_arg(*argp, int))
			&& (set->base = 16))
		putf_u(i, set, ret);
}

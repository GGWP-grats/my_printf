#include "ft_printf.h"

/*
** main goals is to write printf
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

	//print_flags(set);	
	if (**format == 'c' && (c = va_arg(*argp, int)))
		putf_c(c, set, ret);
	else if (**format == 's' && (s = va_arg(*argp, char *)))
		putf_s(s, set, ret);
}

void	get_set(const char **format, va_list *argp, t_pft *set)
{
	while (1)
	{
		if (**format == '-')
			set->f_ladjust = TRUE;
		else if (**format == '0')
			set->zero = TRUE;
		else
			break;
		(*format)++;
	}
	if (ft_isdigit(**format)) 
		set->width = pft_atoi(format);
	else if (**format == '*' && (*format)++)
		if ((set->width= va_arg(*argp, int)) < 0)
			set->width = -(set->width);
	if (**format == '.' && (*format)++)
	{
		set->f_prec = TRUE;
		if (ft_isdigit(**format))
			set->prec_width = pft_atoi(format);
		else if (**format == '*' &&(*format)++)
			if ((set->prec_width = va_arg(*argp, int)) < 0)
				set->f_prec = FALSE;
	}
}
int		print(const char *format, va_list *argp)
{
	int ret;
	t_pft set;

	ret = 0;
	set = (t_pft){0};
	while (*format)
	{
		if (*format != '%')
			putchar_c(*format, &ret);
		else if	(*format == '%')
		{
			format++;
			get_set(&format, argp, &set);
			do_print(&format, argp, &set, &ret);
			set = (t_pft){0};
		}
		format++;
	}
	va_end(*argp);
	return (ret);
}

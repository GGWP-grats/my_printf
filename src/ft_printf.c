#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list arg_list;
	
	va_start(arg_list, format);
	return (start_pf(format, &arg_list));
}

int		start_pf(const char *format, va_list *argp)
{
	int ret;
	t_pft set;

	ret = 0;
	set = (t_pft){0, 0, 0, 0, 0, 0, {0, 0}, 10};
	while (*format)
	{
		if (*format != '%')
			putchar_c(*format, &ret);
		else if	(*format == '%')
		{
			format++;
			get_set(&format, argp, &set);
			do_print(&format, argp, &set, &ret);
			set = (t_pft){0, 0, 0, 0, 0, 0, {0, 0}, 10};
		}
		format++;
	}
	va_end(*argp);
	return (ret);
}

void	get_set(const char **format, va_list *argp, t_pft *set)
{
	while (1)
	{
		if (**format == '-')
			set->ladjust = TRUE;
		else if (**format == '0')
			set->zero = TRUE;
		else
			break;
		(*format)++;
	}
	if (ft_isdigit(**format))
		set->width = ft_skip_atoi(format);
	else if (**format == '*' && (*format)++)
		if ((set->width= va_arg(*argp, int)) < 0)
			set->width = -(set->width);
	if (**format == '.' && (*format)++)
	{
		set->f_prec = TRUE;
		if (ft_isdigit(**format))
			set->prec = ft_skip_atoi(format);
		else if (**format == '*' &&(*format)++)
			if ((set->prec = va_arg(*argp, int)) < 0)
				set->f_prec = FALSE;
	}
}

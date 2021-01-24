/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:32:43 by wquenten          #+#    #+#             */
/*   Updated: 2021/01/24 10:32:46 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list arg_list;

	va_start(arg_list, format);
	return (start_pf(format, &arg_list));
}

int			start_pf(const char *format, va_list *argp)
{
	int		ret;
	t_pft	set;

	ret = 0;
	set = (t_pft){0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0}, 10};
	while (*format)
	{
		if (*format != '%')
			putchar_c(*format, &ret);
		else if (*format == '%')
		{
			format++;
			get_flags(&format, argp, &set);
			do_print(&format, argp, &set, &ret);
			set = (t_pft){0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0}, 10};
		}
		format++;
	}
	va_end(*argp);
	return (ret);
}

void		get_flags(const char **format, va_list *argp, t_pft *set)
{
	while (1)
	{
		if (**format == '-')
			set->ladjust = TRUE;
		else if (**format == '0')
			set->zero = TRUE;
		else if (**format == ' ')
			set->space = TRUE;
		else if (**format == '+')
			set->plus = TRUE;
		else if (**format == '#')
			set->sharp = TRUE;
		else
			break ;
		(*format)++;
	}
	get_set(format, argp, set);
}

void		get_set(const char **format, va_list *argp, t_pft *set)
{
	if (ft_isdigit(**format))
		set->width = ft_skip_atoi(format);
	else if (**format == '*' && (*format)++)
		if ((set->width = va_arg(*argp, int)) < 0)
			set->ladjust = TRUE;
	if (**format == '.' && (*format)++)
	{
		set->f_prec = TRUE;
		if (ft_isdigit(**format))
			set->prec = ft_skip_atoi(format);
		else if (**format == '*' && (*format)++)
			if ((set->prec = va_arg(*argp, int)) < 0)
				set->f_prec = FALSE;
	}
	if (**format == 'l' || **format == 'h')
		(*format)++;
	if (**format == 'l' || **format == 'h')
		(*format)++;
	set->width = set->width > 0 ? set->width : -(set->width);
}

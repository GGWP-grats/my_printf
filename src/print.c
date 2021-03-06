/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:15:01 by wquenten          #+#    #+#             */
/*   Updated: 2021/01/24 10:19:35 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					putchar_c(char c, int *ret)
{
	*ret += 1;
	write(1, &c, 1);
}

void					putnum_base(long i, t_pft *set, int *ret)
{
	int					len;

	len = set->base;
	if (i < 0)
		i = -i;
	if (i >= len)
	{
		putnum_base(i / len, set, ret);
		putnum_base(i % len, set, ret);
	}
	else if (i < len)
		putchar_c(ARR_BASE[i + set->capital], ret);
}

void					u_putnum_base(unsigned long i, t_pft *set, int *ret)
{
	unsigned long		len;

	len = set->base;
	if (i >= len)
	{
		u_putnum_base(i / len, set, ret);
		u_putnum_base(i % len, set, ret);
	}
	else if (i < len)
		putchar_c(ARR_BASE[i + set->capital], ret);
}

int						print_width(t_pft *set, int *ret)
{
	char				c;
	int					i;

	i = 0;
	c = ' ';
	if (set->zero)
		c = '0';
	while (set->width > i++)
		putchar_c(c, ret);
	return (i);
}

void					do_print(const char **format, va_list *argp,\
												t_pft *set, int *ret)
{
	char				*s;
	char				c;
	int					i;
	unsigned long long	lu;

	if (**format == 'c' && !(set->zero = FALSE))
		putf_c(c = va_arg(*argp, int), set, ret);
	else if (**format == 's')
		putf_s(s = va_arg(*argp, char *), set, ret);
	else if (**format == 'd' || **format == 'i')
		putf_i(i = va_arg(*argp, long), set, ret);
	else if (**format == 'u')
		putf_u((i = va_arg(*argp, unsigned long)), set, ret);
	else if (**format == 'x' && (set->base = 16))
		putf_u(lu = va_arg(*argp, unsigned long long), set, ret);
	else if (**format == 'X' && (set->base = 16)
			&& (set->capital = 16))
		putf_u(lu = va_arg(*argp, unsigned long long), set, ret);
	else if (**format == 'p' && (set->base = 16))
		putf_p(s = va_arg(*argp, void *), set, ret);
	else if (**format == '%')
		putf_c('%', set, ret);
	else
		bonus(format, argp, set, ret);
}

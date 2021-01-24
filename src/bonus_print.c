/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:12:52 by wquenten          #+#    #+#             */
/*   Updated: 2021/01/24 10:14:01 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ll_putnum_base(long long i, t_pft *set, int *ret)
{
	int len;

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

void		ull_putnum_base(unsigned long long i, t_pft *set, int *ret)
{
	unsigned long len;

	len = set->base;
	if (i >= len)
	{
		u_putnum_base(i / len, set, ret);
		u_putnum_base(i % len, set, ret);
	}
	else if (i < len)
		putchar_c(ARR_BASE[i + set->capital], ret);
}

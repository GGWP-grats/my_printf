/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:27:05 by wquenten          #+#    #+#             */
/*   Updated: 2021/01/24 10:39:06 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		putf_i(int i, t_pft *set, int *ret)
{
	int		wid;

	wid = ft_intwid(i, set->base);
	if (set->space && i >= 0)
		putchar_c(' ', ret);
	if (set->f_prec && !(set->zero = 0) && !(set->prec) && !i)
		set->width -= print_width(set, ret);
	if (set->prec >= wid)
		set->width -= i > -1 ? set->prec : set->prec + 1;
	else
		set->width -= i > -1 ? wid : wid;
	if (!(set->ladjust) && !(set->zero))
		print_width(set, ret);
	if (i < 0 && wid--)
		putchar_c('-', ret);
	if (!(set->ladjust) && set->zero)
		print_width(set, ret);
	while (set->f_prec && set->prec > wid && set->prec--)
		putchar_c('0', ret);
	if (!set->prec && set->f_prec && !i)
		;
	else
		putnum_base(i, set, ret);
	if (set->ladjust && !(set->zero = 0))
		print_width(set, ret);
}

void		putf_u(unsigned int i, t_pft *set, int *ret)
{
	int		wid;

	wid = ft_intwid(i, set->base);
	if (set->f_prec && !(set->zero = 0) && !(set->prec) && !i)
		set->width -= print_width(set, ret);
	if (set->prec > wid)
		set->width -= set->prefix[0] | set->sharp ? set->prec + 2 : set->prec;
	else
		set->width -= set->prefix[0] | (set->sharp && i) ? wid + 2 : wid;
	if (!set->ladjust && (!set->prefix[0] || !set->zero))
		print_width(set, ret);
	if (set->prefix[0] && (*ret += 2))
		write(1, set->prefix, 2);
	while (set->f_prec && set->prec > wid && set->prec--)
		putchar_c('0', ret);
	if (!set->prec && set->f_prec && !i)
		;
	else
		u_putnum_base(i, set, ret);
	if (set->ladjust && !(set->zero = 0))
		print_width(set, ret);
}

void		putf_s(char *s, t_pft *set, int *ret)
{
	int		len;
	char	p[6];

	ft_strlcpy(p, "(null)", 7);
	if (!s)
		s = p;
	len = ft_strlen(s);
	set->zero = FALSE;
	if (set->f_prec && set->prec < len)
		len = set->prec;
	if (set->ladjust == FALSE && set->width > len
			&& (set->width -= len))
		print_width(set, ret);
	write(1, s, len);
	*ret += len;
	if (set->ladjust && set->width > len
			&& (set->width -= len))
		print_width(set, ret);
}

void		putf_c(char c, t_pft *set, int *ret)
{
	if (set->width > 0 &&
			set->ladjust == FALSE && set->width--)
		print_width(set, ret);
	putchar_c(c, ret);
	set->width--;
	set->zero = FALSE;
	if (set->ladjust)
		print_width(set, ret);
}

void		putf_p(void *p, t_pft *set, int *ret)
{
	(set->prefix)[0] = '0';
	(set->prefix)[1] = set->capital == 16 ? 'X' : 'x';
	putf_llu((unsigned long long)p, set, ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:18:56 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/17 17:56:50 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long		sign;
	long long	num;

	sign = 1;
	num = 0;
	while ((*str < 15 && *str > 0) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && num < 2147483648)
		num = num * 10 + (*str++ - '0');
	if (num * sign < -2147483648)
		return (0);
	else if (num * sign > 2147483647)
		return (-1);
	else
		return ((int)(num * sign));
}

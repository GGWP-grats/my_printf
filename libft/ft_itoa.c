/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:42:04 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/10 16:12:15 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		revstr(char *str)
{
	int		i;
	int		k;
	char	c;

	i = 0;
	k = 0;
	while (str[++k])
		;
	k--;
	while (i < k)
	{
		c = str[i];
		str[i] = str[k];
		str[k] = c;
		i++;
		k--;
	}
}

static int		get_size_itoa(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	num;

	if (!(str = (char *)malloc(sizeof(char) * get_size_itoa(n))))
		return (NULL);
	i = 0;
	if (n < 0)
		num = -n;
	else
		num = n;
	if (num == 0)
		str[i++] = '0';
	while (num)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	revstr(str);
	return (str);
}

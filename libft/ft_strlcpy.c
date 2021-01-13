/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:25:00 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/10 14:44:14 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		n;
	const char	*s;
	char		*d;

	if (!src || !dst)
		return (0);
	s = src;
	d = dst;
	n = dstsize;
	if (n)
	{
		while (--n)
		{
			if ((*d++ = *s++) == '\0')
				break ;
		}
	}
	while (!n && dstsize)
	{
		*d++ = '\0';
		n--;
	}
	return (ft_strlen(src));
}

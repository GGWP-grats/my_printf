/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:12:37 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/14 13:28:34 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	if (!*s && !c)
		return ((char *)s);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
		if (*s == (unsigned char)c)
			return ((char *)s);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:44:55 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/10 18:00:14 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	if (s)
	{
		if (!(ptr = (char *)malloc(ft_strlen(s) + 1)))
			return (NULL);
		i = 0;
		while (s[i])
		{
			ptr[i] = (*f)(i, s[i]);
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	else
		return (NULL);
}

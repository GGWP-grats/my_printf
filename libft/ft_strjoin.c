/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:07:41 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/14 16:43:39 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	size;
	int		i;

	new_str = NULL;
	if (s1 && s2)
	{
		size = sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!(new_str = (char *)malloc(size)))
			return (NULL);
		i = 0;
		while (*s1)
			new_str[i++] = *s1++;
		while (*s2)
			new_str[i++] = *s2++;
		new_str[i] = '\0';
		return (new_str);
	}
	return (NULL);
}

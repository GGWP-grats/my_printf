/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:53:00 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/19 16:04:47 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	int		i;

	i = 0;
	if (s)
	{
		if (!(new_str = (char *)malloc(((len + 1) * sizeof(char)))))
			return (NULL);
		if (ft_strlen(s) < start)
		{
			new_str[0] = '\0';
			return (new_str);
		}
		while (s[start] && len--)
			new_str[i++] = s[start++];
		new_str[i] = '\0';
		return (new_str);
	}
	return (NULL);
}

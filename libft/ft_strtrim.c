/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:22:17 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/15 14:03:45 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cut(char const *s, char const *set, int start)
{
	int i;

	i = 0;
	if (start == 0)
	{
		while (s[i])
		{
			if (!(ft_strchr(set, s[i])))
				return (i);
			else
				i++;
		}
	}
	else if (start > 0)
	{
		i = start;
		while (i)
		{
			if (!(ft_strchr(set, s[i])))
				return (start - i);
			else
				i--;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s_len;
	int		start;
	int		end;
	char	*new_str;

	if (s1 && set)
	{
		s_len = ft_strlen(s1);
		start = cut(s1, set, 0);
		end = cut(s1, set, s_len - 1);
		s_len = s_len - start - end;
		if (!(new_str = (char *)malloc(sizeof(char) * (s_len + 1))))
			return (NULL);
		ft_memcpy(new_str, s1 + start, s_len);
		new_str[s_len] = '\0';
		return (new_str);
	}
	return (NULL);
}

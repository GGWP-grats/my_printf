/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:56:19 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/24 16:58:34 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int		words_c;
	int		i;

	words_c = 0;
	i = 0;
	while (*s)
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			words_c++;
		}
		s++;
	}
	return (words_c);
}

char		**ft_split(char const *s, char c)
{
	int		words;
	char	**new_str;
	int		i;
	int		words_count;
	int		start;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(new_str = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	words_count = -1;
	while (++words_count < words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		new_str[words_count] = ft_substr(s, start, i - start);
		i++;
	}
	new_str[words_count] = NULL;
	return (new_str);
}

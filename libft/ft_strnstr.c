/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:25:49 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/14 20:46:55 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int k;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && len)
	{
		k = 0;
		while (haystack[i + k] == needle[k] && needle[k] && (len - k) != 0)
			k++;
		if (!needle[k])
			return ((char *)&haystack[i]);
		i++;
		len--;
	}
	return (NULL);
}

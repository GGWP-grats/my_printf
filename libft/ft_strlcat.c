/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:25:25 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/14 15:49:43 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *s, size_t max)
{
	size_t len;

	len = 0;
	while (*s && len < max)
	{
		len++;
		s++;
	}
	return (len);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dlen;
	size_t slen;

	dlen = ft_strnlen(dst, dstsize);
	slen = ft_strlen(src);
	if (dlen == dstsize)
		return (dstsize + slen);
	if (slen < dstsize - dlen)
	{
		ft_memcpy(dst + dlen, src, slen + 1);
	}
	else
	{
		ft_memcpy(dst + dlen, src, dstsize - dlen - 1);
		dst[dlen + (dstsize - dlen) - 1] = '\0';
	}
	return (dlen + slen);
}

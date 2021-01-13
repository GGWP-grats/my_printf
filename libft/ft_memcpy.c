/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:55:09 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/10 14:40:04 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	int				i;

	if (!dst && !src)
		return (NULL);
	i = -1;
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (++i < (int)n)
		cdst[i] = csrc[i];
	return (dst);
}

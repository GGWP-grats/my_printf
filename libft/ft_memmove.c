/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:39:57 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/14 13:15:54 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dp;
	unsigned char *sp;

	if (!src && !dst)
		return (NULL);
	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	if (dp <= sp || dp >= (sp + len))
	{
		while (len--)
			*dp++ = *sp++;
	}
	else
	{
		sp += len - 1;
		dp += len - 1;
		while (len--)
			*dp-- = *sp--;
	}
	return (dst);
}

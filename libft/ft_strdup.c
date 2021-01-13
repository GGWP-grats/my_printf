/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:27:30 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/10 14:41:01 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *newstr;

	if (!(newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	else
	{
		ft_memcpy(newstr, s1, sizeof(char) * (ft_strlen(s1) + 1));
		return (newstr);
	}
}

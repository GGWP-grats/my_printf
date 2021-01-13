/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:59:41 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/17 16:24:26 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int counter;

	counter = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			counter++;
		}
	}
	return (counter);
}

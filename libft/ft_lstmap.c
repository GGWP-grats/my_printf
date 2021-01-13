/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquenten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:26:41 by wquenten          #+#    #+#             */
/*   Updated: 2020/11/17 19:36:39 by wquenten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *first;

	if (!lst)
		return (NULL);
	else
	{
		first = NULL;
		while (lst)
		{
			if ((new_list = ft_lstnew(f(lst->content))))
				ft_lstadd_back(&first, new_list);
			else
			{
				ft_lstclear(&first, del);
				return (NULL);
			}
			lst = lst->next;
		}
		return (first);
	}
}

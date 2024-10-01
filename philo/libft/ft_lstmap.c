/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:12:35 by beboccas          #+#    #+#             */
/*   Updated: 2024/01/30 21:00:12 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*i;

	if (!lst || !f || !del)
		return (0);
	final = ft_lstnew(f(lst->content));
	if (!final)
		return (0);
	i = final;
	lst = lst->next;
	while (lst)
	{
		final->next = ft_lstnew(f(lst->content));
		if (!final->next)
		{
			ft_lstclear(&i, del);
			return (0);
		}
		final = final->next;
		lst = lst->next;
	}
	final->next = 0;
	return (i);
}

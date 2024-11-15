/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:26:20 by pibernar          #+#    #+#             */
/*   Updated: 2024/10/05 17:05:32 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Iterates the list ’lst’ and applies the function
* ’f’ on the content of each node. Creates a new
* list resulting of the successive applications of
* the function ’f’. The ’del’ function is used to
* delete the content of a node if needed
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
			return (ft_lstclear(&new, del), NULL);
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}

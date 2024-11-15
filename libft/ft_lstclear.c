/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:20:23 by pibernar          #+#    #+#             */
/*   Updated: 2024/10/05 16:38:18 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Deletes and frees the given node and every
* successor of that node, using the function ’del’
* and free(3).
* Finally, the pointer to the list must be set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*temp;

	cur = *lst;
	while (cur)
	{
		temp = cur;
		cur = cur->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}

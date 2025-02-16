/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:37:41 by maelgini          #+#    #+#             */
/*   Updated: 2025/02/15 12:14:06 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!(list))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

// int main()
// {
//     int value1 = 42;
//     int value2 = 84;
//     int value3 = 168;

//     t_list *node1 = ft_lstnew(&value1);
//     t_list *node2 = ft_lstnew(&value2);
//     t_list *node3 = ft_lstnew(&value3);

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     t_list *current = node1;
//     int index = 1;
//     while (current != NULL)
//     {
//         printf("Nœud %d: contenu = %d\n", index, *(int *)(current->content));
//         current = current->next;
//         index++;
//     }
//     free(node1);
//     free(node2);
//     free(node3);

//     return 0;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:30:03 by maelgini          #+#    #+#             */
/*   Updated: 2025/02/16 13:41:28 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Initializes push values to avoid conditional jumps on uninitialized values
void	init_values(t_push *push)
{
	push->next = 0;
	push->max = 0;
	push->mid = 0;
	push->flag = 0;
}

// Initializes stack values to avoid conditional jumps on uninitialized values
void	initialize_flags(t_list *stack)
{
	while (stack)
	{
		stack->flag = 0;
		stack = stack->next;
	}
}

//Frees the list
void	ft_free(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

// Frees the array of strings allocated by ft_split (was causing a memory leak)
void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// Frees the list before returning
void	ft_free_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

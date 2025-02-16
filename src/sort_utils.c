/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:54:17 by maelgini          #+#    #+#             */
/*   Updated: 2025/02/16 13:28:37 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Check if the stack is sorted
int	check_sorting(t_list **stack1)
{
	t_list	*tmp;

	tmp = *stack1;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// Check if the stack is sorted
int	check_sorting_a(t_list **stack1, int count)
{
	int	len;

	len = ft_lstsize(*stack1);
	if (len != count)
		return (0);
	if (check_sorting(stack1) == 0)
		return (0);
	return (1);
}

// Find the minimum value in the stack
t_list	*find_min_lst(t_list **stack)
{
	t_list	*min;
	t_list	*tmp;

	if (*stack == NULL)
		return (NULL);
	min = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

// Find the maximum value in the stack
t_list	*find_max_lst(t_list **stack)
{
	t_list	*max;
	t_list	*tmp;

	if (*stack == NULL)
		return (NULL);
	max = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

// Check if the stack is reverse sorted
int	isrevsorted(t_swap	*tab)
{
	t_list	*tmp;

	tmp = tab->stack_a;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

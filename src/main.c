/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:51:55 by maelgini          #+#    #+#             */
/*   Updated: 2025/02/16 13:43:07 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Parses the arguments and checks if they are valid
int	ft_check(t_list *lst, int n, char *nbr)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (nbr[i])
	{
		if (!(((nbr[i] == '-' || nbr[i] == '+') && ft_isdigit(nbr[i + 1])
					&& (i == 0 || !ft_isdigit(nbr[i - 1])))
				|| ft_isdigit(nbr[i])))
			return (0);
		i++;
	}
	while (tmp)
	{
		if (tmp->content == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

//Initializes the stack with the arguments
t_list	*ft_init(char **ag, int ac)
{
	t_list	*tmp;
	t_list	*res;
	int		i;
	long	nbr;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	res = NULL;
	while (ag[i])
	{
		nbr = ft_atoi(ag[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || ft_check(res, nbr, ag[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			ft_free(res);
			return (NULL);
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&res, tmp);
		tmp->index = -1;
		i++;
	}
	return (res);
}

//Initializes the tab structure
int	initialize_tab(t_swap *tab, char **args, int ac)
{
	tab->stack_a = ft_init(args, ac);
	if (tab->stack_a == NULL)
	{
		free(tab);
		if (ac == 2)
			ft_free_split(args);
		return (-1);
	}
	tab->stack_b = NULL;
	tab->asize = ft_lstsize(tab->stack_a);
	tab->bsize = ft_lstsize(tab->stack_b);
	add_index(tab->stack_a);
	return (0);
}

//free function for main
void	cleanup(t_swap *tab, char **args, int ac)
{
	ft_free(tab->stack_a);
	ft_free(tab->stack_b);
	if (ac == 2)
		ft_free_split(args);
	free(tab);
}

int	main(int ac, char **ag)
{
	t_swap	*tab;
	char	**args;

	if (ac == 1)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	if (ac == 2)
		args = ft_split(ag[1], ' ');
	else
		args = ag;
	if (initialize_tab(tab, args, ac) == -1)
		return (-1);
	check_sort(tab);
	cleanup(tab, args, ac);
	return (0);
}

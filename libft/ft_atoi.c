/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelgini <maelgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:55 by maelgini          #+#    #+#             */
/*   Updated: 2025/02/16 13:27:36 by maelgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int	skip_whitespace_and_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || **str == '\t' || **str == '\n'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
	if (**str == '-')
		sign = -1;
	if (**str == '-' || **str == '+')
		(*str)++;
	return (sign);
}

long	ft_atoi(const char *str)
{
	int		sign;
	long	nb;

	sign = skip_whitespace_and_sign(&str);
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (nb > (LONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		nb = nb * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (LONG_MAX);
	return (nb * sign);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	printf("%d\n", atoi(av[1]));
// 	printf("%d", ft_atoi(av[1]));
// 	return (0);
// }

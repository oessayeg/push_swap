/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_stack2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:32:38 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/11 20:18:44 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	len_of(t_list *stack)
{
	int	compteur;

	compteur = 0;
	while (stack != NULL)
	{
		compteur++;
		stack = stack->previous;
	}
	return (compteur);
}

int	find_biggest_nb(t_list *stack)
{
	int	return_value;

	return_value = stack->value;
	while (stack != NULL)
	{
		if (stack->value > return_value)
			return_value = stack->value;
		stack = stack->previous;
	}
	return (return_value);
}

int	check_e(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

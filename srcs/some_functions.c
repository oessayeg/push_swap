/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:37:23 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/08 15:35:24 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	abso(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

int	tr(int nbr, t_list *stack_b)
{
	if (nbr > len_of(stack_b) / 2)
		return (-1 * (len_of(stack_b) - nbr));
	return (nbr);
}

int	one_of_them(t_list *stack_a, int nb, int res)
{
	if (res == 0 && nb < find_smallest(stack_a))
		return (find_s_place(stack_a));
	return (0);
}

int	sort_arr_give_med(int *arr, int len)

{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr[len / 2]);
}

void	get_to_top(t_list **stack_a, int n)
{
	while ((*stack_a)->value != n)
	{
		if (find_position(*stack_a, n) <= (len_of(*stack_a) / 2))
			ra(*stack_a, 1);
		else if (find_position(*stack_a, n) > (len_of(*stack_a) / 2))
			rra(stack_a, 1);
	}	
}

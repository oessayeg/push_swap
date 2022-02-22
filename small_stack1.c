/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:18:11 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/08 15:42:38 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_small(t_list **top_a, int arg)
{
	if (arg == 3)
		sa(*top_a, 1);
	if (arg == 4)
		sort_three(top_a);
}

void	sort_three(t_list **top_a)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = (*top_a)->value;
	nb2 = (*top_a)->previous->value;
	nb3 = (*top_a)->previous->previous->value;
	if (nb1 > nb2 && nb1 > nb3 && nb2 < nb3)
		ra(*top_a, 1);
	else if (nb3 > nb2 && nb3 > nb1 && nb1 > nb2)
		sa(*top_a, 1);
	else if (nb3 < nb2 && nb3 < nb1 && nb1 < nb2)
		rra(top_a, 1);
	else if (nb1 < nb2 && nb1 < nb3 && nb2 > nb3)
	{
		sa(*top_a, 1);
		ra(*top_a, 1);
	}
	else if (nb1 > nb2 && nb1 > nb3 && nb2 > nb3)
	{
		sa(*top_a, 1);
		rra(top_a, 1);
	}
}

int	find_smallest(t_list *stack)
{
	int	smallest;

	smallest = stack->value;
	while (stack != NULL)
	{
		if (stack->value < smallest)
			smallest = stack->value;
		stack = stack->previous;
	}
	return (smallest);
}

int	find_position(t_list *top_a, int nb)
{
	int	position;

	position = 0;
	while (top_a->value != nb)
	{
		position++;
		top_a = top_a->previous;
	}
	return (position + 1);
}

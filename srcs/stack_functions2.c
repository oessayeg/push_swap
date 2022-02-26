/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:09:29 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/09 10:06:58 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_list *top_a, int option)
{
	int		temp;
	t_list	*add;

	if (top_a == NULL || len_of(top_a) == 1)
		return ;
	temp = top_a->value;
	while (top_a->previous != NULL)
	{
		add = top_a;
		top_a = top_a->previous;
		add->value = top_a->value;
	}
	top_a->value = temp;
	if (option == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list *top_b, int option)
{
	int		temp;
	t_list	*add;

	if (top_b == NULL || len_of(top_b) == 1)
		return ;
	temp = top_b->value;
	while (top_b->previous != NULL)
	{
		add = top_b;
		top_b = top_b->previous;
		add->value = top_b->value;
	}
	top_b->value = temp;
	if (option == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list *top_a, t_list *top_b, int option)
{
	if (top_a != NULL && len_of(top_a) > 1)
		ra(top_a, 0);
	if (top_b != NULL && len_of(top_b) > 1)
		rb(top_b, 0);
	if (option == 1)
		write(1, "rr\n", 3);
}

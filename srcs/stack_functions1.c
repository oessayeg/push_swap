/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:08:31 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/09 10:06:19 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_list *top_a, int option)
{
	t_list	*add;
	int		temp;

	if (top_a == NULL || len_of(top_a) == 1)
		return ;
	add = top_a;
	add = top_a->previous;
	temp = add->value;
	add->value = top_a->value;
	top_a->value = temp;
	if (option == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list *top_b, int option)
{
	t_list	*add;
	int		temp;

	if (top_b == NULL || len_of(top_b) == 1)
		return ;
	add = top_b;
	add = top_b->previous;
	temp = add->value;
	add->value = top_b->value;
	top_b->value = temp;
	if (option == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list *top_a, t_list *top_b, int option)
{
	if (top_a != NULL && len_of(top_a) > 1)
		sa(top_a, 0);
	if (top_b != NULL && len_of(top_b) > 1)
		sb(top_b, 0);
	if (option == 1)
		write(1, "ss\n", 3);
}

void	pa(t_list **top_b, t_list **top_a, int option)
{
	if ((*top_b) == NULL)
		return ;
	push((*top_b)->value, top_a);
	pop(top_b);
	if (option == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **top_a, t_list **top_b, int option)
{
	if ((*top_a) == NULL)
		return ;
	push((*top_a)->value, top_b);
	pop(top_a);
	if (option == 1)
		write(1, "pb\n", 3);
}

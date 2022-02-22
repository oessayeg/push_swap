/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:10:16 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/09 10:09:01 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_list **top_a, int option)
{
	t_list	*ptr;
	t_list	*test;

	if ((*top_a) == NULL || len_of(*top_a) == 1)
		return ;
	ptr = *top_a;
	test = *top_a;
	while (ptr->previous != NULL)
		ptr = ptr->previous;
	push(ptr->value, top_a);
	while (test->previous->previous != NULL)
		test = test->previous;
	test->previous = NULL;
	free(ptr);
	if (option == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **top_b, int option)
{
	t_list	*ptr;
	t_list	*test;

	if ((*top_b) == NULL || len_of(*top_b) == 1)
		return ;
	ptr = *top_b;
	test = *top_b;
	while (ptr->previous != NULL)
		ptr = ptr->previous;
	push(ptr->value, top_b);
	while (test->previous->previous != NULL)
		test = test->previous;
	test->previous = NULL;
	free(ptr);
	if (option == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **top_a, t_list **top_b, int option)
{
	if ((*top_a) != NULL && len_of(*top_a) > 1)
		rra(top_a, 0);
	if ((*top_b) != NULL && len_of(*top_b) > 1)
		rrb(top_b, 0);
	if (option == 1)
		write(1, "rrr\n", 4);
}

void	push(int number, t_list **top)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		free_pre_nodes(top);
		return ;
	}
	node->value = number;
	if (*top == NULL)
		node->previous = NULL;
	else
		node->previous = *top;
	*top = node;
}

void	pop(t_list **top)
{
	t_list	*tmp;

	tmp = *top;
	*top = (*top)->previous;
	free (tmp);
}

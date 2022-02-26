/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:17:19 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/08 15:42:32 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	negative_work(int *arr, t_list **stack_a, t_list **stack_b)
{
	while (arr[1] < 0 && arr[2] < 0)
	{
		rrr(stack_a, stack_b, 1);
		arr[1]++;
		arr[2]++;
	}
	while (arr[1] < 0)
	{
		rra(stack_a, 1);
		arr[1]++;
	}
	while (arr[2] < 0)
	{
		rrb(stack_b, 1);
		arr[2]++;
	}
	pa(stack_b, stack_a, 1);
}

void	positive_work(int *arr, t_list **stack_a, t_list **stack_b)
{
	while (arr[1] > 0 && arr[2] > 0)
	{
		rr(*stack_a, *stack_b, 1);
		arr[1]--;
		arr[2]--;
	}
	while (arr[1] > 0)
	{
		ra(*stack_a, 1);
		arr[1]--;
	}
	while (arr[2] > 0)
	{
		rb(*stack_b, 1);
		arr[2]--;
	}
	pa(stack_b, stack_a, 1);
}

void	put1(int *arr, t_list **stack_a, t_list **stack_b)
{
	while (arr[1] > 0)
	{
		ra(*stack_a, 1);
		arr[1]--;
	}
	while (arr[2] < 0)
	{
		rrb(stack_b, 1);
		arr[2]++;
	}
	pa(stack_b, stack_a, 1);
}

void	put2(int *arr, t_list **stack_a, t_list **stack_b)
{
	while (arr[1] < 0)
	{
		rra(stack_a, 1);
		arr[1]++;
	}
	while (arr[2] > 0)
	{
		rb(*stack_b, 1);
		arr[2]--;
	}
	pa(stack_b, stack_a, 1);
}

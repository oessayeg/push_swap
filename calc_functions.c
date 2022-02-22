/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   For125.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:24:36 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/11 20:18:00 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_everything_to_a(t_list **top_a, t_list **top_b)
{
	int	*arr;
	int	i;

	i = 0;
	while ((*top_b) != NULL)
	{
		arr = find_the_best(*top_a, *top_b);
		if (arr[1] <= 0 && arr[2] <= 0)
			negative_work(arr, top_a, top_b);
		else if (arr[1] >= 0 && arr[2] >= 0)
			positive_work(arr, top_a, top_b);
		else if (arr[1] > 0 && arr[2] < 0)
			put1(arr, top_a, top_b);
		else if (arr[1] < 0 && arr[2] > 0)
			put2(arr, top_a, top_b);
		free(arr);
		i++;
	}
	while ((*top_a)->value != find_smallest(*top_a))
	{
		if (find_position(*top_a, find_smallest(*top_a)) < len_of(*top_a) / 2)
			ra(*top_a, 1);
		else
			rra(top_a, 1);
	}
}

int	*find_the_best(t_list *top_a, t_list *top_b)
{
	int		actions_b;
	t_list	*add;
	int		*arr;

	actions_b = 0;
	arr = ft_calloc(3, sizeof(int));
	arr[0] = top_b->value;
	arr[1] = send_actions(arr[0], top_a);
	arr[2] = 0;
	add = top_b;
	add = add->previous;
	actions_b++;
	while (add != NULL)
	{
		if ((abso(send_actions(add->value, top_a))
				+ abso(tr(actions_b, top_b))) < (abso((arr[1]) + abso(arr[2]))))
		{
			arr[0] = add->value;
			arr[1] = send_actions(add->value, top_a);
			arr[2] = tr(actions_b, top_b);
		}
		actions_b++;
		add = add->previous;
	}
	return (arr);
}

int	send_actions(int nb, t_list *stack_a)
{
	int		res;
	int		pos;
	t_list	*add;

	res = 0;
	add = stack_a;
	pos = 1;
	while (add->previous != NULL)
	{
		if (add->value < nb && add->previous->value > nb)
		{
			res = 1;
			break ;
		}
		pos++;
		add = add->previous;
	}
	if (res == 1 && pos > (len_of(stack_a) / 2))
		return (-1 * (len_of(stack_a) - pos));
	else if (res == 0 && nb > find_biggest_nb(stack_a))
		return ((nb_actions(stack_a)));
	else if (res == 0)
		return (one_of_them(stack_a, nb, res));
	return (pos);
}

int	nb_actions(t_list *top_a)
{
	int		i;
	t_list	*add;

	add = top_a;
	i = 0;
	while (add->value != find_biggest_nb(top_a))
	{
			add = add->previous;
			i++;
	}
	if (add->previous == NULL)
		return (0);
	if (i > len_of(top_a) / 2)
		return ((-1 * (len_of(top_a) - i)) + 1);
	return (i + 1);
}

int	find_s_place(t_list *top_a)
{
	int		i;
	t_list	*add;

	add = top_a;
	i = 0;
	while (add->value != find_smallest(top_a))
	{
		i++;
		add = add->previous;
	}
	if (i > (len_of(top_a) / 2))
		return (-1 * (len_of(top_a) - i));
	return (i);
}

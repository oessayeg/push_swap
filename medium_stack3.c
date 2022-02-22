/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_stack2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:54:11 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/08 15:42:27 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	max_in_arr(int *arr, int len, int *l)
{
	int	i;
	int	biggest;

	i = 1;
	biggest = arr[0];
	while (i < len)
	{
		if (arr[i] > biggest)
			biggest = arr[i];
		i++;
	}
	*l = biggest;
	i = 0;
	while (arr[i] != biggest)
		i++;
	return (i);
}

int	*find_lis_here(int *arr_nb, int *lis_arr, int len)
{
	int	i;
	int	j;
	int	to_comp;

	lis_arr = malloc(sizeof(int) * (len));
	lis_arr = init(lis_arr, len);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr_nb[i] > arr_nb[j])
			{
				to_comp = lis_arr[j] + 1;
				if (to_comp > lis_arr[i])
					lis_arr[i] = to_comp;
			}
			j++;
		}
		i++;
	}
	return (lis_arr);
}

int	*init(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		array[i] = 1;
		i++;
	}
	return (array);
}

int	*push_to_me(t_list *top_a, int argc)
{
	int	*unsorted_arr;
	int	i;

	i = 0;
	unsorted_arr = malloc(sizeof(int) * (argc - 1));
	while (top_a != NULL)
	{
		unsorted_arr[i] = top_a->value;
		i++;
		top_a = top_a->previous;
	}
	return (unsorted_arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:17:30 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/11 20:18:34 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_everything(t_list **top_a, t_list **top_b, int argc)
{
	int	*arr;
	int	*lis_arr;
	int	*to_stay_a;
	int	len_arr[2];

	to_stay_a = NULL;
	lis_arr = NULL;
	arr = push_to_me(*top_a, argc);
	lis_arr = find_lis_here(arr, lis_arr, argc - 1);
	to_stay_a = get_me_nb(arr, lis_arr, argc - 1, to_stay_a);
	max_in_arr(lis_arr, argc - 1, &len_arr[0]);
	len_arr[1] = sort_arr_give_med(arr, len_arr[0]);
	get_these_to_b(to_stay_a, top_a, top_b, len_arr);
	push_everything_to_a(top_a, top_b);
	free(arr);
	free(lis_arr);
	free(to_stay_a);
}

void	get_these_to_b(int *arr, t_list **top_a, t_list **top_b, int *len_arr)
{
	t_list	*st;

	while (len_of(*top_a) > (*len_arr))
	{
		st = *top_a;
		while (st != NULL)
		{
			if (is_not(st->value, arr, (*len_arr)) == 0)
			{
				get_to_top(top_a, st->value);
				pb(top_a, top_b, 1);
				if ((*top_b)->value > len_arr[1])
					rb(*top_b, 1);
				break ;
			}
			st = st->previous;
		}
	}
}

int	is_not(int number, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == number)
			return (1);
		i++;
	}
	return (0);
}

int	*get_me_nb(int *arr_nb, int *lis_arr, int len, int *ret_array)
{
	int	index_of_bi;
	int	len_of_new;

	index_of_bi = max_in_arr(lis_arr, len, &len_of_new);
	ret_array = malloc(len_of_new * sizeof(int));
	ret_array = fill_me(index_of_bi, arr_nb, lis_arr, ret_array);
	return (ret_array);
}

int	*fill_me(int index, int *arr_nb, int *lis_arr, int *ret_array)
{
	int	i;
	int	n;

	n = lis_arr[index];
	ret_array[0] = arr_nb[index];
	index--;
	i = 1;
	while (index >= 0)
	{
		if (lis_arr[index] == n - 1)
		{
			n = lis_arr[index];
			ret_array[i] = arr_nb[index];
			i++;
		}
		index--;
	}
	return (ret_array);
}

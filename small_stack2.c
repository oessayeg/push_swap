/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:19:57 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/11 20:18:55 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_small2(t_list **s_a, t_list **s_b, int n)
{
	int	smallest;

	if (n == 5)
	{
		smallest = find_smallest(*s_a);
		while ((*s_a)->value != find_smallest(*s_a))
		{
			if (find_position(*s_a, smallest) <= len_of(*s_a) / 2)
				ra(*s_a, 1);
			else if (find_position(*s_a, smallest) > len_of(*s_a) / 2)
				rra(s_a, 1);
		}
		pb(s_a, s_b, 1);
		sort_three(s_a);
		pa(s_b, s_a, 1);
	}
	else if (n == 6)
		sort_small3(s_a, s_b, n);
}

void	sort_small3(t_list **s_a, t_list **s_b, int n)
{
	int	smallest;

	n--;
	while (n > 3)
	{
		smallest = find_smallest(*s_a);
		while ((*s_a)->value != smallest)
		{
			if (find_position(*s_a, smallest) <= len_of(*s_a) / 2)
				ra(*s_a, 1);
			else if (find_position(*s_a, smallest) > len_of(*s_a) / 2)
				rra(s_a, 1);
		}
		pb(s_a, s_b, 1);
		n--;
	}
	sort_three(s_a);
	pa(s_b, s_a, 1);
	pa(s_b, s_a, 1);
}

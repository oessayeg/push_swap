/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:24:56 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/11 20:20:13 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (check_e(argv) == 0 || check_everything(argc, argv) == 0)
		exit(EXIT_SUCCESS);
	push_everything(argv, &stack_a, argc);
	if (is_sorted(stack_a) == 0)
	{
		if (argc <= 4)
			sort_small(&stack_a, argc);
		else if (argc <= 6)
			sort_small2(&stack_a, &stack_b, argc);
		else
			sort_everything(&stack_a, &stack_b, argc);
	}
}

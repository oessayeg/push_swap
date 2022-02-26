/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:01:37 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/11 20:18:18 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../srcs/push_swap.h"

void	everything2(char **argv, int argc)
{
	char	*m[3];

	if (argc == 2)
	{
		m[0] = NULL;
		m[1] = argv[1];
		m[2] = NULL;
		if (argv[1][0] == '\0' || !check_int(m) ||
			!check_i(m) || !check_dup(m))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		else
			return ;
	}
	if (check_e(argv) == 0 || check_everything(argc, argv) == 0)
		exit(EXIT_FAILURE);
}

void	do_instruction(int i, t_list **stack_a, t_list **stack_b)
{
	if (i == 1)
		sa(*stack_a, 0);
	else if (i == 2)
		sb(*stack_b, 0);
	else if (i == 3)
		ss(*stack_a, *stack_b, 0);
	else if (i == 4)
		ra(*stack_a, 0);
	else if (i == 5)
		rb(*stack_b, 0);
	else if (i == 6)
		rr(*stack_a, *stack_b, 0);
	else if (i == 7)
		rra(stack_a, 0);
	else if (i == 8)
		rrb(stack_b, 0);
	else if (i == 9)
		rrr(stack_a, stack_b, 0);
	else if (i == 10)
		pa(stack_b, stack_a, 0);
	else if (i == 11)
		pb(stack_a, stack_b, 0);
}

void	free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

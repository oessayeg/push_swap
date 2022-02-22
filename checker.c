/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:00:49 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/11 20:20:43 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	everything2(argv, argc);
	push_everything(argv, &stack_a, argc);
	read_instructions(&stack_a, &stack_b);
	if (is_sorted(stack_a) == 1 && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

void	read_instructions(t_list **stack_a, t_list **stack_b)
{
	char	*string;
	int		inst_number;

	string = NULL;
	string = get_next_line(0);
	if (string == NULL)
		return ;
	inst_number = check_instruction(string);
	do_instruction(inst_number, stack_a, stack_b);
	free(string);
	while (string != NULL)
	{
		string = get_next_line(0);
		if (string == NULL)
			return ;
		inst_number = check_instruction(string);
		do_instruction(inst_number, stack_a, stack_b);
		free(string);
	}
}

int	check_instruction(char *string)
{
	int		i;
	char	*ins;
	char	**instr;

	ins = "sa\n sb\n ss\n ra\n rb\n rr\n rra\n rrb\n rrr\n pa\n pb\n";
	instr = ft_split(ins, ' ');
	i = 0;
	while (instr[i] != NULL)
	{
		if (ft_strncmp(instr[i], string,
				ft_strlen(instr[i])) == 0
			&& string[ft_strlen(instr[i])] == '\0')
		{
			free_all(instr);
			return (i + 1);
		}
		i++;
	}
	ft_putstr_fd("Error\n", 2);
	free(string);
	free_all(instr);
	exit(EXIT_FAILURE);
}

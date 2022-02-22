/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:16:21 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/11 20:18:28 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	f_atoi(char *s)
{
	int	compteur;
	int	return_value;

	compteur = 0;
	return_value = 0;
	if (s[0] == '-')
		compteur++;
	while (s[compteur] != '\0')
	{
		return_value = return_value * 10 + (s[compteur] - 48);
		compteur++;
	}
	if (s[0] == '-')
		return (return_value * (-1));
	return (return_value);
}

int	f_isalpha(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (-1);
}

void	push_everything(char **string, t_list **stack, int argc)
{
	argc--;
	while (argc > 0)
	{
		push(f_atoi(string[argc]), stack);
		argc--;
	}
}

int	is_sorted(t_list *top)
{
	int	to_comp;

	if (top == NULL)
		return (0);
	while (top->previous != NULL)
	{
		to_comp = top->value;
		top = top->previous;
		if (to_comp > top->value)
			return (0);
	}
	return (1);
}

int	check_everything(int argc, char **str)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		if (str[1][0] == '-' && str[1][1] != '\0')
			i++;
		while (str[1][i] != '\0')
		{
			if (f_isalpha(str[1][i]) == -1 || !check_max_int(str[1]))
			{
				write(2, "Error\n", 6);
				break ;
			}
			i++;
		}
	}
	if (argc < 3)
		return (0);
	if (!check_int(str) || (!check_i(str)) || (!check_dup(str)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

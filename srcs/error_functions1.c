/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:13:12 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/11 20:18:23 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_int(char **string)
{
	int	i1;
	int	i2;

	i1 = 1;
	while (string[i1] != NULL)
	{
		i2 = 0;
		while (string[i1][i2] != '\0')
		{
			if (i2 == 0 && string[i1][i2] == '-' && string[i1][i2 + 1] != '\0')
				i2++;
			else
			{
				if (f_isalpha(string[i1][i2]) == -1)
					return (0);
				i2++;
			}
		}
		i1++;
	}
	return (1);
}

int	check_max_int(char *string)
{
	long long	return_value;
	int			compteur;

	compteur = 0;
	return_value = 0;
	if (string[0] == '-')
		compteur++;
	while (string[compteur] != '\0')
	{
		return_value = return_value * 10 + (string[compteur] - 48);
		if (string[0] != '-' && return_value > 2147483647)
			return (0);
		else if (string[0] == '-' && return_value > 2147483648)
			return (0);
		compteur++;
	}
	return (1);
}

int	check_i(char **st)
{
	int	compteur;

	compteur = 1;
	while (st[compteur] != NULL)
	{
		if (check_max_int(st[compteur]) == 0)
			return (0);
		compteur++;
	}
	return (1);
}

int	check_dup(char **str)
{
	int	i1;
	int	i2;
	int	to_comp;

	i1 = 1;
	while (str[i1] != NULL)
	{
		i2 = i1 + 1;
		to_comp = f_atoi(str[i1]);
		while (str[i2] != NULL)
		{
			if (f_atoi(str[i2]) == to_comp)
				return (0);
			i2++;
		}
		i1++;
	}
	return (1);
}

void	free_pre_nodes(t_list **top)
{
	t_list	*tmp;

	while (*top != NULL)
	{
		tmp = *top;
		*top = (*top)->previous;
		free(tmp);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:48:28 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/11 20:19:43 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct s_list
{
	int				value;
	struct s_list	*previous;
}t_list;
int		f_isalpha(char c);
int		check_int(char **string);
int		check_max_int(char *string);
int		check_i(char **st);
int		check_dup(char **str);
int		f_atoi(char *s);
int		is_sorted(t_list *top);
int		check_everything(int argc, char **str);
int		find_smallest(t_list *stack);
int		find_position(t_list *top_a, int nb);
int		*push_to_me(t_list *top_a, int argc);
int		len_of(t_list *top_a);
int		find_biggest_nb(t_list *stack);
int		*find_lis_here(int *arr_nb, int *lis_arr, int len);
int		*init(int *array, int len);
int		max_in_arr(int *arr, int len, int *l);
int		*get_me_nb(int *arr_nb, int *lis_arr, int len, int *ret_array);
int		*fill_me(int index, int *arr_nb, int *lis_arr, int *ret_array);
int		is_not(int number, int *arr, int len);
int		*find_the_best(t_list *top_a, t_list *top_b);
int		send_actions(int nb, t_list *stack_a);
int		nb_actions(t_list *top_a);
int		find_s_place(t_list *top_a);
int		abso(int nbr);
int		tr(int nbr, t_list *stack_b);
int		one_of_them(t_list *stack_a, int nb, int res);
int		sort_arr_give_med(int *arr, int len);
int		check_instruction(char *string);
int		check_e(char **argv);
int		check_it(char *st);
void	push(int number, t_list **top);
void	pop(t_list **top);
void	sa(t_list *top_a, int option);
void	sb(t_list *top_b, int option);
void	ss(t_list *top_a, t_list *top_b, int option);
void	pa(t_list **top_b, t_list **top_a, int option);
void	pb(t_list **top_a, t_list **top_b, int option);
void	ra(t_list *top_a, int option);
void	rb(t_list *top_b, int option);
void	rr(t_list *top_a, t_list *top_b, int option);
void	rra(t_list **top_a, int option);
void	rrb(t_list **top_b, int option);
void	rrr(t_list **top_a, t_list **top_b, int option);
void	free_pre_nodes(t_list **top);
void	push_everything(char **string, t_list **stack, int argc);
void	sort_small(t_list **top_a, int arg);
void	sort_three(t_list **top_a);
void	sort_everything(t_list **top_a, t_list **top_b, int argc);
void	sort_small2(t_list **top_a, t_list **top_b, int argc);
void	push_everything_to_a(t_list **top_a, t_list **top_b);
void	negative_work(int *arr, t_list **stack_a, t_list **stack_b);
void	positive_work(int *arr, t_list **stack_a, t_list **stack_b);
void	put1(int *arr, t_list **stack_a, t_list **stack_b);
void	put2(int *arr, t_list **stack_a, t_list **stack_b);
void	sort_small3(t_list **s_a, t_list **s_b, int n);
void	get_these_to_b(int *arr, t_list **top_a, t_list **top_b, int *len_arr);
void	get_to_top(t_list **stack_a, int n);
void	read_instructions(t_list **stack_a, t_list **stack_b);
void	free_all(char **s);
void	do_instruction(int i, t_list **stack_a, t_list **stack_b);
void	everything2(char **argv, int argc);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:39:48 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/24 22:12:27 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_list
{
	int					index;
	int					curr_pos;
	int					n;
	int					cost;
	struct s_stack_list	*next;
	struct s_stack_list	*target;
}						t_stack_list;

// 						operations

void					sa(t_stack_list **stack);
void					ss(t_stack_list **a, t_stack_list **b);
void					sb(t_stack_list **b);
void					push(t_stack_list **src_stack,
							t_stack_list **dest_stack, char push_stack_name);
void					rr(t_stack_list **a, t_stack_list **b);
void					rotate(t_stack_list **stack, char stack_name);
void					rev_rotate_both(t_stack_list **a, t_stack_list **b);
void					rev_rotate(t_stack_list **stack, char which_stack);

//						utils

t_stack_list			*find_last_node(t_stack_list *stack);
long					ft_atol(char *str);
void					init_stack(t_stack_list **stack, char **av,
							int is_split);
void					set_index(t_stack_list **stack);
t_stack_list			*find_biggest_node(t_stack_list *stack);
int						stack_len(t_stack_list *stack);
int						take_max_index(t_stack_list *stack);
int						how_many_chunks(int stack_size);
int						take_index_position(t_stack_list *stack, int index);
void					push_chunk_to_b(t_stack_list **a, t_stack_list **b,
							int chunk_max, int chunk_min);
t_stack_list			*take_min_node(t_stack_list *stack);
int						how_many_chunks(int stack_size);
t_stack_list			*find_low_cost_node(t_stack_list *b);
void					calculate_cost(t_stack_list *a, t_stack_list *b_head,
							t_stack_list *curr);

//						checkers

int						check_if_dup(t_stack_list **stack, int n);
int						check_input(char *str);
int						is_sorted(t_stack_list *stack);

//						sorting

void					sort_big(t_stack_list **a, t_stack_list **b);
void					sort_3(t_stack_list **stack);
void					sort_4_5(t_stack_list **a, t_stack_list **b);
void					push_b_to_a(t_stack_list **a, t_stack_list **b);

//						free

void					free_stack(t_stack_list **stack);
void					free_error(t_stack_list **stack, char **av,
							int is_split);
void					free_split(char **split);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:37:45 by mmilicev          #+#    #+#             */
/*   Updated: 2025/05/02 21:05:40 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	how_many_chunks(int stack_size)
{
	if (stack_size <= 100)
		return (4);
	else
		return (10);
}

int	take_index_position(t_stack_list *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

static int	is_in_chunk(t_stack_list *stack, int max, int min)
{
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	take_chunk_pos(t_stack_list *stack, int max, int min)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	push_chunk_to_b(t_stack_list **a, t_stack_list **b, int chunk_max,
		int chunk_min)
{
	int	node_pos_in_chunk;

	while (is_in_chunk(*a, chunk_max, chunk_min))
	{
		node_pos_in_chunk = take_chunk_pos(*a, chunk_max, chunk_min);
		if (node_pos_in_chunk == -1)
			return ;
		if (node_pos_in_chunk <= stack_len(*a) / 2)
			while (node_pos_in_chunk-- > 0)
				rotate(a, 'a');
		if (node_pos_in_chunk > stack_len(*a) / 2)
			while (node_pos_in_chunk++ <= stack_len(*a))
				rev_rotate(a, 'a');
		push(a, b, 'b');
	}
}

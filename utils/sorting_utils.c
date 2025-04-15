/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:23:54 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/15 22:50:27 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	how_many_chunks(int stack_size)
{
	if (stack_size <= 50)
		return (4);
	if (stack_size <= 100)
		return (6);
	if (stack_size <= 200)
		return (8);
	if (stack_size <= 300)
		return (9);
	if (stack_size <= 400)
		return (10);
	else
		return (13);
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
	int	chunk_pos;

	while (is_in_chunk(*a, chunk_max, chunk_min))
	{
		chunk_pos = take_chunk_pos(*a, chunk_max, chunk_min);
		if (chunk_pos <= stack_len(*a) / 2)
			while (chunk_pos-- > 0)
				rotate(a, 'a');
		if (chunk_pos > stack_len(*a) / 2)
			while (chunk_pos++ <= stack_len(*a))
				rev_rotate(a, 'a');
		push(a, b, 'b');
	}
}

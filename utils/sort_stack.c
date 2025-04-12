/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:09:10 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/13 01:26:57 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_n_in_chunk(t_stack_list *stack, int min, int max)
{
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	sort_3(t_stack_list **stack)
{
	int	biggest;

	if (stack_len(*stack) != 3)
		return ;
	biggest = find_biggest_node(*stack);
	if ((*stack)->n == biggest)
		rotate(stack, 'a');
	if ((*stack)->next->n == biggest)
		rev_rotate(stack, 'a');
	if ((*stack)->n > (*stack)->next->n)
		sa(stack);
}

int	get_position(t_stack_list *stack, int min, int max)
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
	return (-1); // nije našao nijedan
}

void	sort(t_stack_list **a, t_stack_list **b)
{
	int				chunk_size;
	int				chunk_max;
	int				chunk_min;
	int				max_index;
	t_stack_list	*tmp;
	int				pos;
	int				size;
    int             size_stack;

    size_stack = stack_len(*a);
	chunk_size = size_stack / 10;
	if (chunk_size == 0)
		chunk_size = 1;
	chunk_max = chunk_size - 1;
	chunk_min = 0;
	set_index(a);
	while (chunk_max < size_stack )
	{
		while (is_n_in_chunk(*a, chunk_min, chunk_max))
		{
			pos = get_position(*a, chunk_min, chunk_max);
			size = stack_len(*a);
			if (pos <= size / 2)
				while (pos-- > 0)
					rotate(a, 'a');
			else
				while (pos++ < size)
					rev_rotate(a, 'a');
			push(a, b, 'b');
		}
		chunk_min += chunk_size;
		chunk_max += chunk_size;
	}
	sort_3(a);
    set_index(a);
	set_index(b);
	while (*b)
	{
		max_index = take_max_index(*b);
		tmp = *b;
		while (tmp && tmp->index != max_index)
			tmp = tmp->next;
		if (tmp && tmp->is_above_med)
		{
			while ((*b)->index != max_index)
				rotate(b, 'b');
		}
		else
		{
			while ((*b)->index != max_index)
				rev_rotate(b, 'b');
		}
		push(b, a, 'a');
	}
}

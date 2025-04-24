/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:09:10 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/24 21:57:17 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack_list **stack)
{
	t_stack_list	*biggest;

	if (stack_len(*stack) != 3)
		return ;
	biggest = find_biggest_node(*stack);
	if ((*stack)->n == biggest->n)
		rotate(stack, 'a');
	if ((*stack)->next->n == biggest->n)
		rev_rotate(stack, 'a');
	if ((*stack)->n > (*stack)->next->n)
		sa(stack);
}

void	sort_4_5(t_stack_list **a, t_stack_list **b)
{
	int				len;
	t_stack_list	*smallest;

	len = stack_len(*a);
	set_index(a);
	while (len-- > 3)
	{
		smallest = take_min_node(*a);
		while ((*a)->n != smallest->n)
		{
			if (smallest->curr_pos <= stack_len(*a) / 2)
				rotate(a, 'a');
			else
				rev_rotate(a, 'a');
		}
		push(a, b, 'b');
	}
	sort_3(a);
	if (stack_len(*b) == 2)
		push(b, a, 'a');
	push(b, a, 'a');
}

static void	finish_sort(t_stack_list **a)
{
	t_stack_list	*smallest;

	smallest = take_min_node(*a);
	while (*a != smallest)
	{
		if (smallest->curr_pos <= stack_len(*a) / 2)
			rotate(a, 'a');
		else
			rev_rotate(a, 'a');
	}
}

void	sort_big(t_stack_list **a, t_stack_list **b)
{
	int	chunk_size;
	int	chunk_max;
	int	chunk_min;

	chunk_size = stack_len(*a) / how_many_chunks(stack_len(*a));
	chunk_max = chunk_size - 1;
	chunk_min = 0;
	set_index(a);
	while (stack_len(*a) > 0)
	{
		push_chunk_to_b(a, b, chunk_max, chunk_min);
		chunk_max += chunk_size;
		chunk_min += chunk_size;
	}
	set_index(b);
	push_b_to_a(a, b);
	finish_sort(a);
}

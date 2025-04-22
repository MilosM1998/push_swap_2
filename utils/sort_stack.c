/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:09:10 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/15 23:33:31 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_curr_position(t_stack_list *stack, int n)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->n == n)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
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
void	sort_4_5(t_stack_list **a, t_stack_list **b)
{
	int	len;
	int	smallest;

	len = stack_len(*a);
	set_index(a);
	while (len-- > 3 && !is_sorted(*a))
	{
		smallest = find_smallest_node(*a);
		while ((*a)->n != smallest)
		{
			if (get_curr_position(*a, smallest) <= stack_len(*a) / 2)
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
static int take_min_index(t_stack_list *stack)
{
	int min_index;
	
	min_index = INT_MAX;
	while(stack)
	{
		if(stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return min_index;
}
static void finish_sort(t_stack_list **a)
{
	int min_index;

	min_index = take_min_index(*a);
	while((*a)->index != min_index)
	{
		if(get_curr_position(*a, min_index) <= stack_len(*a) / 2)
			rotate(a, 'a');
		else
			rev_rotate(a, 'a');
	}
}
void	sort_big(t_stack_list **a, t_stack_list **b)
{
	int	stack_size;
	int chunk_size;
	int	chunk_max;
	int	chunk_min;
	
	stack_size = stack_len(*a);
	chunk_size = stack_size / how_many_chunks(stack_size);
	chunk_max = chunk_size - 1;
	chunk_min = 0;
	set_index(a);
	while (stack_size-- > 3 && !is_sorted(*a))
	{
		push_chunk_to_b(a, b, chunk_max, chunk_min);
		chunk_max += chunk_size;
		chunk_min += chunk_size;
	}
	sort_3(a);
	set_index(a);
	set_index(b);
	push_b_to_a(a, b);
	finish_sort(a);
}

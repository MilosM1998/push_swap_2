/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:09:10 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/13 18:27:52 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_curr_position(t_stack_list *stack, int n)
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
	if(stack_len(*b) == 2)
		push(b, a, 'a');
	push(b, a, 'a'); 
}
int get_chunk_count(int size)
{
	if (size <= 50)
		return (4);
	else if (size <= 100)
		return (6);
	else if (size <= 200)
		return (9);
	else if (size <= 300)
		return (12);
	else if (size <= 400)
		return (18);
	else
		return (13);
}

int has_in_chunk(t_stack_list *stack, int min, int max)
{
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int get_position_of_chunk(t_stack_list *stack, int min, int max)
{
	int i = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int get_max_index(t_stack_list *stack)
{
	int max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int get_position_of_index(t_stack_list *stack, int index)
{
	int i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void push_chunk_to_b(t_stack_list **a, t_stack_list **b, int min, int max)
{
	while (has_in_chunk(*a, min, max))
	{
		int pos = get_position_of_chunk(*a, min, max);
		int len = stack_len(*a);
		if (pos <= len / 2)
			while (pos-- > 0)
				rotate(a, 'a');
		else
			while (pos++ < len)
				rev_rotate(a, 'a');
		push(a, b, 'b');
	}
}

void sort_from_b_to_a(t_stack_list **a, t_stack_list **b)
{
	while (*b)
	{
		int max_index = get_max_index(*b);
		int pos = get_position_of_index(*b, max_index);
		int len = stack_len(*b);
		if (pos <= len / 2)
			while ((*b)->index != max_index)
				rotate(b, 'b');
		else
			while ((*b)->index != max_index)
				rev_rotate(b, 'b');
		push(b, a, 'a');
	}
}

void sort_big(t_stack_list **a, t_stack_list **b)
{
	int stack_size = stack_len(*a);
	int chunk_count = get_chunk_count(stack_size);
	int chunk_size = stack_size / chunk_count;
	int chunk_min = 0;
	int chunk_max = chunk_size - 1;

	set_index(a);

	while (stack_len(*a) > 3)
	{
		push_chunk_to_b(a, b, chunk_min, chunk_max);
		chunk_min += chunk_size;
		chunk_max += chunk_size;
	}

	sort_3(a);
	sort_from_b_to_a(a, b);
}


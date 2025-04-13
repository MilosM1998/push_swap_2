/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:43:33 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/13 15:25:17 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_biggest_node(t_stack_list *stack)
{
	int	biggest;

	if (!stack)
		return (0);
	biggest = stack->n;
	while (stack)
	{
		if (stack->n > biggest)
			biggest = stack->n;
		stack = stack->next;
	}
	return (biggest);
}
void	set_median(t_stack_list *stack)
{
	int				curr_pos;
	int				median;

	curr_pos = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		if (curr_pos <= median)
			stack->is_above_med = 1;
		else
			stack->is_above_med = 0;
		curr_pos++;
		stack = stack->next;
	}
}
void	set_index(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*curr_n;
	int				index;

	set_median(*stack);
	tmp = *stack;
	while (tmp)
	{
		index = 0;
		curr_n = *stack;
		while (curr_n)
		{
			if (curr_n->n < tmp->n)
				index++;
			curr_n = curr_n->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}
int	take_max_index(t_stack_list *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}
int	find_smallest_node(t_stack_list *stack)
{
	int smallest;

	smallest = stack->n;
	while (stack)
	{
		if (stack->n < smallest)
			smallest = stack->n;
		stack = stack->next;
	}
	return (smallest);
}
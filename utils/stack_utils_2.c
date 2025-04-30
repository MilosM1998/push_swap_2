/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:37:55 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/30 09:37:57 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_list	*find_biggest_node(t_stack_list *stack)
{
	t_stack_list	*biggest_node;
	int				biggest;

	if (!stack)
		return (0);
	biggest_node = NULL;
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->n > biggest)
		{
			biggest = stack->n;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	set_index(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*curr_n;
	int				i;
	int				index;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->curr_pos = i;
		index = 0;
		curr_n = *stack;
		while (curr_n)
		{
			if (curr_n->n < tmp->n)
				index++;
			curr_n = curr_n->next;
		}
		tmp->index = index;
		i++;
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

t_stack_list	*take_min_node(t_stack_list *stack)
{
	t_stack_list	*min_node;
	long			min_n;

	if (!stack)
		return (NULL);
	min_n = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->n < min_n)
		{
			min_n = stack->n;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_list	*find_low_cost_node(t_stack_list *b)
{
	t_stack_list	*low_cost_node;
	int				cost;

	if (!b)
		return (NULL);
	low_cost_node = NULL;
	cost = INT_MAX;
	while (b)
	{
		if (b->cost < cost)
		{
			cost = b->cost;
			low_cost_node = b;
		}
		b = b->next;
	}
	return (low_cost_node);
}

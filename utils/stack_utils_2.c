/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:43:33 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/13 00:42:04 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_biggest_node(t_stack_list *stack)
{
	int				biggest;
	t_stack_list	*tmp;

	if (!stack)
		return (0);
	biggest = 0;
	tmp = stack;
	biggest = stack->n;
	while (tmp)
	{
		if (tmp->n > biggest)
			biggest = tmp->n;
		tmp = tmp->next;
	}
	return (biggest);
}
void	set_index(t_stack_list **stack)
{
	t_stack_list	*tmp;
	t_stack_list	*curr_n;
	int				index;
	int				median;

	tmp = *stack;
	median = stack_len(*stack) / 2;
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
		if (tmp->index >= median)
			tmp->is_above_med = 1;
		else
			tmp->is_above_med = 0;
		tmp = tmp->next;
	}
}
int	take_max_index(t_stack_list *stack)
{
	int max;

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
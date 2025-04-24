/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:05:41 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/24 20:59:13 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_targets(t_stack_list *a, t_stack_list *b)
{
	int				closest_bigger;
	t_stack_list	*target;
	t_stack_list	*tmp;

	tmp = a;
	closest_bigger = INT_MAX;
	target = NULL;
	while (tmp)
	{
		if (tmp->n > b->n && tmp->n < closest_bigger)
		{
			target = tmp;
			closest_bigger = tmp->n;
		}
		tmp = tmp->next;
	}
	if (closest_bigger == INT_MAX)
		b->target = take_min_node(a);
	else
		b->target = target;
}

void	prepare_for_push(t_stack_list *a, t_stack_list *b)
{
	t_stack_list	*tmp;

	tmp = b;
	while (tmp)
	{
		set_targets(a, tmp);
		calculate_cost(a, b, tmp);
		tmp = tmp->next;
	}
}

static void	rotate_stacks(t_stack_list **a, t_stack_list **b,
		t_stack_list *low_cost_node)
{
	if (low_cost_node->curr_pos <= stack_len(*b) / 2
		&& low_cost_node->target->curr_pos <= stack_len(*a) / 2)
		while (*a != low_cost_node->target && *b != low_cost_node)
			rr(a, b);
	if (low_cost_node->target->curr_pos > stack_len(*a) / 2
		&& low_cost_node->curr_pos > stack_len(*b) / 2)
		while (*a != low_cost_node->target && *b != low_cost_node)
			rev_rotate_both(a, b);
	set_index(a);
	set_index(b);
}

static void	find_and_rotate(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*low_cost_node;

	low_cost_node = find_low_cost_node(*b);
	if (!low_cost_node || !low_cost_node->target)
		return ;
	rotate_stacks(a, b, low_cost_node);
	if (low_cost_node->curr_pos <= stack_len(*b) / 2)
		while (*b != low_cost_node)
			rotate(b, 'b');
	if (low_cost_node->curr_pos > stack_len(*b) / 2)
		while (*b != low_cost_node)
			rev_rotate(b, 'b');
	if (low_cost_node->target->curr_pos <= stack_len(*a) / 2)
		while (*a != low_cost_node->target)
			rotate(a, 'a');
	if (low_cost_node->target->curr_pos > stack_len(*a) / 2)
		while (*a != low_cost_node->target)
			rev_rotate(a, 'a');
	set_index(a);
	set_index(b);
}

void	push_b_to_a(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*biggest;

	biggest = NULL;
	if (!(*a))
	{
		biggest = find_biggest_node(*b);
		while (*b != biggest)
		{
			if (biggest->curr_pos <= stack_len(*b) / 2)
				rotate(b, 'b');
			else
				rev_rotate(b, 'b');
		}
		push(b, a, 'a');
	}
	set_index(a);
	set_index(b);
	while (*b)
	{
		prepare_for_push(*a, *b);
		find_and_rotate(a, b);
		push(b, a, 'a');
		set_index(a);
		set_index(b);
	}
}
